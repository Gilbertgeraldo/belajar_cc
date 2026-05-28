#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = NULL;
    }
};

void Traverse(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next;
    }cout << "NULL" << endl;
}

void insertAtHead(Node* &head,int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head,int val) {
    if (head = NULL) {
        insertAtHead(head,val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteEndNode(Node* head) {
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        free(delNode);
    }
}

int main() {

    Node* head = NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    Traverse(head);
    deleteEndNode(head);
    Traverse(head);
    return 0;
}