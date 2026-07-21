#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node* prev;

    Node(int v){
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

void forwardTraversal(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->value << "<->";
        temp = temp->next;
    }cout << "NULL" << endl;
}

void backwardTraversal(Node* head){
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    while(temp){
        cout << temp->value << "<->";
        temp = temp->prev;
    }cout << "NULL" << endl;
}

void insertAtStart(Node* &head,int v){
    Node* newNode = new Node(v);
    while(head == nullptr){
        head = newNode;
        return;  
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node* head,int v){
    Node* newNode = new Node(v);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* lastNode = head;
    while(lastNode->next){
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

void insertAtMiddle(Node* head,int v,int pos){
    if(pos == 1){
        insertAtStart(head,v);
        return;
    }
    Node* temp = head;
    for (int i = 1;i < pos-1;i++){
        temp = temp->next;
    }

    Node* newNode = new Node(v);
    if(temp->next){
        temp->next->prev = newNode;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtStart(Node* &head){
    if(head->next == nullptr){
        delete head;
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);

    n1->next = n2;
    n2->prev = n1;
    Node* head = n1;
    forwardTraversal(head);
    backwardTraversal(head);
    insertAtStart(head,3);
    forwardTraversal(head);
    insertAtMiddle(head,2,3);
    forwardTraversal(head);
    deleteAtStart(head);
    forwardTraversal(head);

    return 0;
}