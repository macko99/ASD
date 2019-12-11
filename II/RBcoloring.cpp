#include <iostream>
using namespace std;
struct Node {
    int w;
    char color;
    int black_quota;
    int min_h;
    int h;
    Node* left;
    Node* right;
};
Node* create_node(int w)
{
    Node* node = new Node;
    node->w = w;
    node->left = nullptr;
    node->right = nullptr;
    node->min_h = 0;
    node->h = 0;
    node->color = 'h'; // h bo chuj wie jaki kolor
    return node;
}
void insert(Node* &tree, int w)
{
    if(tree == nullptr)
    {
        tree = create_node(w);
        return;
    }
    if(w > tree->w)
    {
        if(tree->right == nullptr)
            tree->right = create_node(w);
        else
            insert(tree->right, w);
    }
    else
    {
        if(tree->left == nullptr)
            tree->left = create_node(w);
        else
            insert(tree->left, w);
    }
}

void height_count(Node* tree)
{
    if(tree == nullptr)
        return;
    if(tree->left == nullptr && tree->right == nullptr)
        return;
    height_count(tree->left);
    height_count(tree->right);
    
    if(tree->left != nullptr)
        tree->h = tree->left->h + 1;
    if(tree->right != nullptr)
        if(tree->h < tree->right->h + 1)
            tree->h = tree->right->h + 1;
    
    if(tree->right != nullptr && tree->left != nullptr)
        tree->min_h = min(tree->right->min_h, tree->left->min_h) + 1;
    else
        tree->min_h = 0;
}

bool color_tree(Node* tree, int black_quota, char parent_color)
{
    if(tree == nullptr)
    {
        if(parent_color == 'r')
            return black_quota == -1;
        else
            return black_quota == 0;
    }
    if(tree->color != 'h')
        return color_tree(tree->left, black_quota, tree->color)
                && color_tree(tree->right, black_quota, tree->color);
    
    if(parent_color == 'r')
    {
        tree->color = 'b';
        return color_tree(tree->left, black_quota, tree->color)
                && color_tree(tree->right, black_quota, tree->color);
    }
    else
    {
        int new_quota = black_quota - 1;
        if(tree->min_h < new_quota)
            return false;
        if(tree->h - 1 <= 2*new_quota)
            tree->color = 'b';
        else
            tree->color = 'r';
        return color_tree(tree->left, new_quota, tree->color)
                && color_tree(tree->right, new_quota, tree->color);
    }
}

void print_tree(Node* tree)
{
    if(tree == nullptr) return;
    cout<<tree->w<<" "<<tree->color<<endl;
    print_tree(tree->left);
    print_tree(tree->right);
}
int main()
{
    int n, k;
    Node* root = nullptr;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        insert(root, k);
    }
    
    height_count(root);
    root->color = 'b';
    
    bool done = color_tree(root, (root->h) / 2, 'h');
    if(done) print_tree(root);
    else cout<<"NO!";
    return 0;
}
