#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* removeKey(Node* head,int key) {
    while(head != nullptr && head->data == key){
        head = head->next;
    }

    if (head == nullptr){
        return nullptr;
    }

    Node* curr = head;
    while(curr->next != nullptr){
        if (curr->next->data == key){
            curr->next = curr->next->next;
        }else {
            curr = curr->next;
        }
    }
    return head;
}