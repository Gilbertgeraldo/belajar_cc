#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left,*right;
    Node(int v):val(v),left(nullptr),right(nullptr){}
};

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    

    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* cur = st.top();
        st.pop();

        cout << cur->val<< " ";

        if (cur->right) {
            st.push(cur->right);
        }

        if (cur->left) {
            st.push(cur->left);
        }
    }
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> st;    
}