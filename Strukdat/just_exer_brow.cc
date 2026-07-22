#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int v){
        value = v;
        next = nullptr;
    }
};

void addHead(Node* head,int v){
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

void addEnd(Node* head,int v){
    Node* temp = head;
    Node* lastNode = new Node(v);
    if(head == nullptr){
        head = lastNode;
        return;
    }
    while(lastNode->next != nullptr){
        temp = temp->next;
    }
    lastNode->next = temp;
}

int countlen(Node* head){
    int c = 0;
    Node* temp = head;
    while(temp != nullptr){
        temp = temp->next;
        c++;
    }
    return c;
}

int findMaxVal(Node* head){
    if(head == nullptr) return 0;

    Node* curr = head;
    int maxval = head->value;
    int len = countlen(head);
    for (int i = 1;i <= len;++i){
        if(curr->value > maxval){
            maxval = curr->value;
        }
        curr = curr->next;
    }
    return maxval;
}

int findMinVal(Node* head){
    if(head == nullptr) return 0;

    Node* curr = head;
    int minVal = head->value;
    int len = countlen(head);
    for(int i = 1;i <= len;++i){
        if(curr->value < minVal){
            minVal = curr->value;
        }
        curr = curr->next;
    }
    return minVal;
}

Node* getNodeAt(Node* head, int idx) {
    Node* curr = head;
    for (int i = 0; i < idx && curr != nullptr; i++) {
        curr = curr->next;
    }
    return curr;
}

void insertionsortLinkedList(Node* head){
    Node* curr = head;
    Node* prev = nullptr;
    int sub = 0;
    int clen = countlen(head);
    while(sub <= clen - 1){
        int ins = sub + 1;
        int t = sub;
        while(t >= 0 && getNodeAt(head,t)->value > getNodeAt(head,t+1)->value){
            Node* left = getNodeAt(head,t);
            Node* right = left->next;

            int temp = left->value;
            left->value = right->value;
            right->value = temp;
            ins--;
            t--;
        }
        sub++;
    }
}