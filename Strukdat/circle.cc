#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = nullptr;
    }
};


void insertNew(Node*& head, int v) {

    Node* newNode = new Node(v);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* curr = head;

    while (curr->next != head) {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = head;
}

void traverse(Node* head) {

    if (head == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node* temp = head;

    do {
        cout << temp->value << "->";

        temp = temp->next;

    } while (temp != head);

    cout << "HEAD" << endl;
}

void deleteAtStart(Node* &head){
    if(head->next == nullptr){
        delete head;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete head;

}

void deleteAtEnd(Node* &head){
    if(head == nullptr){
        return;
    }

    if(head->next == head){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    Node* secondLastNode = temp->next;
    temp->next = head;
    delete secondLastNode;
}


int main() {

    Node* head = nullptr;

    insertNew(head, 10);
    insertNew(head, 20);
    insertNew(head, 30);
    insertNew(head, 40);
    insertNew(head, 50);
    deleteAtEnd(head);

    traverse(head);

    return 0;
}

