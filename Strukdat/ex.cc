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
    while(temp != NULL) {
        cout << temp->value <<"->";
        temp = temp->next;
    }cout <<"NULL" << endl;
}

void insertAtHead(Node* &head,int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void inserAtEnd(Node* &head,int val) {
    if (head == NULL) {
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

void insertAtMiddle(Node* &head,int val,int position) {
    if (position == 1) {
        insertAtHead(head,val);
    }

    Node* newnode = new Node(val);
    Node* prev = head;
    int count = 1;
    while(count < (position - 1)) {
        prev = prev->next;
        count++;
    }
    newnode->next = prev->next;
    prev->next = newnode;
}

void deleteAtHead(Node* &head) {
    if(head == NULL) {
        return;
    }

    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(Node* &head) {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
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

void deleteAtMiddle(Node* &head,int position) {
    if (position == 1) {
        deleteAtHead(head);
        return;
    }

    Node* prev = head;
    int count = 1;
    while(count < (position - 1)) {
        prev = prev->next;
        count++;
    }

    Node* curr = prev->next;
    prev->next = curr->next;
    free(curr);
}

void deleteAlternateNode(Node* &head) {
    Node* temp = head;
    while(temp != NULL && temp->next != NULL) {
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        free(deleteNode); 
    }
}

int findMiddleNode(Node* head) {
    if (head == NULL) {
        return -1;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    //slow is now at the middle node
    return slow->value; 
}

int main() {
    Node* head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    cout << findMiddleNode(head) << endl;
}

