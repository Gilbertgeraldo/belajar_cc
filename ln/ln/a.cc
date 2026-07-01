#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = NULL;
    }
};

void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
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
    if (head == NULL) {
        insertAtHead(head,val);
        return;
    }
    Node* newnode = new Node(val);
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = newnode;
}

void insertAtMiddle(Node* &head,int val,int pos) {
    if (pos == 1) {
        insertAtHead(head,val);
        return;
    }
    Node* newnode = new Node(val);
    Node* prev = head;
    int count = 1;
        prev = prev->next;
    while(count < (pos - 1)) {
        count++;
    }

    newnode->next = prev->next;
    prev->next = newnode;
}

void deleteAtHead(Node* &head) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(Node* head) {
    if (head ==  NULL){
        return;
    }

    if(head->next == NULL) {
        deleteAtHead(head);
        return;
    }
    Node* secondLast = head;
    while(secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }
    Node* lastNode = secondLast->next;
    secondLast->next = NULL;
    free(lastNode);
}

void deleteAtMiddle(Node* head,int pos) {
    if (pos == 1) {
        deleteAtHead(head);
        return;
    }
    Node* prev = head;
    int c = 1;
    while(c < (pos - 1)) {
        prev = prev->next;
        c++;
    }

    //prev is pointing to node at pos - 1
    Node* curr = prev->next;
    prev->next = curr->next;
    free(curr);
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);

    Node* head = node1;

    traverse(head);

    insertAtHead(head, 3);
    traverse(head);

    insertAtEnd(head, 4);
    traverse(head);

    insertAtMiddle(head, 5, 3);
    traverse(head);

    deleteAtHead(head);
    traverse(head);

    deleteAtEnd(head);
    traverse(head);

    deleteAtMiddle(head, 2);    
    traverse(head);

    return 0;
}