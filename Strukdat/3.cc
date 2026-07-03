#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct Node {
    int val;
    Node *left,*right;
    Node(int v) : val(v),left(nullptr),right(nullptr){}
};

void preOrder(Node* root) {
    if  (!root) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Pre-Order : ";
    preOrder(root);
    cout << "\n";

    cout << "In-Order : ";
    inOrder(root);
    cout << "\n";

    cout << "Post-Order : ";
    postOrder(root);
    cout << "\n";

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}