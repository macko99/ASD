#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX / 2;

typedef struct Segment {
	int town, travel_time;
} Segment;

typedef struct Line {
	Segment* segments;
	int number, length, start_town;
} Line;

Line* newLine(int number, int length, int start_town) {
	Line* l = new Line;
	l->number = number;
	l->length = length;
	l->start_town = start_town;
	l->segments = new Segment[length];
	return l;
}

int** calculateTimesMatrix(Line** lines, int lines_no, int towns) {
	int **result = new int *[towns];
	for(int i=0; i<towns; i++){
        result[i] = new int[towns];
        for(int j=0; j<towns; j++){
            if(i == j) result[i][j] = 0;
            else result[i][j] = INF;
        }

	}
	for(int i=0; i<lines_no; i++){
        Line *p = lines[i];
        int prev = p->start_town;
        for(int j=0; j<p->length; j++){
            Segment next = p->segments[j];
            result[prev][next.town] = min(next.travel_time, result[prev][next.town]);
            result[next.town][prev] = min(next.travel_time, result[next.town][prev]);
            prev = next.town;
        }
	}

    for(int k=0; k<towns; k++)
        for(int i=0; i<towns; i++)
            for(int j=0; j<towns; j++)
                if(result[i][j] > result[i][k] + result[k][j])
                    result[i][j] = result[i][k] + result[k][j];
    return result;

}

int main() {
	int towns, lines_no, queries;
	cin >> towns >> lines_no >> queries;
	Line** lines = new Line*[lines_no];
	for (int i=0; i<lines_no; i++) {
		int len, start;
		cin >> len >> start;
		lines[i] = newLine(i, len-1, start);
		for (int j=0; j<len-1; j++) {
			int next, time;
			cin >> time >> next;
			lines[i]->segments[j].town = next;
			lines[i]->segments[j].travel_time = time;
		}
	}

	int** times = calculateTimesMatrix(lines, lines_no, towns);

	for (int i=0; i<queries; i++) {
		int u, v;
		cin >> u >> v;
		cout << times[u][v] << endl;
	}

	for (int i=0; i<towns; i++) delete[] times[i];
	delete[] times;
	for (int i=0; i<lines_no; i++) {
		delete[] lines[i]->segments;
		delete lines[i];
	}
	delete[] lines;
}
