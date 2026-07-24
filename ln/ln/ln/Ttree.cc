#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Tree {

    struct Node { //Node pada binary tree
        T data;
        Node* left; //pointer tree ke kiri
            Node* right; //pointer tree ke kanan

            Node(T d) { //untuk isi nodenya
            this->data = d;
            this->left = this->right = nullptr;
        }
    };

public:
    Node* Root = nullptr;//root

    Tree() { //make the tree
        Node* f = new Node('F');
        Node* b = new Node('B');
        Node* g = new Node('G');
        Node* a = new Node('A');
        Node* d = new Node('D');
        Node* i = new Node('I');
        Node* c = new Node('C');
        Node* e = new Node('E');
        Node* h = new Node('H');

        f->left = b;
        f->right = g;

        b->left = a;
        b->right = d;

        g->right = i;

        d->left = c;
        d->right = e;

        i->left = h;

        Root = f;
    }

    void preorder(Node* ptr) {
        if (ptr != nullptr) {
            cout << ptr->data << " "; //Root
            preorder(ptr->left); //left
            preorder(ptr->right); //right
        } //Root->Left->Right
    }

    void inorder(Node* ptr) {
        if (ptr != nullptr) {
            inorder(ptr->left); //left
            cout << ptr->data << " "; //root
            inorder(ptr->right); //right
        } //left->root->right
    }

    void postorder(Node* ptr) {
        if (ptr != nullptr) {
            postorder(ptr->left); //left
            postorder(ptr->right); //right
            cout << ptr->data << " "; //root
        } //left->right->root
    }
};

int main() {

    Tree<char> obj;

    if (obj.Root == nullptr) {
        cout << "Tree is empty\n";
    }
    else {
        cout << "Preorder Traversal : ";
        obj.preorder(obj.Root);

        cout << "\nInorder Traversal : ";
        obj.inorder(obj.Root);

        cout << "\nPostorder Traversal : ";
        obj.postorder(obj.Root);
    }

    return 0;
}