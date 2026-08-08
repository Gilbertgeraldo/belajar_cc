#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node* prev;

    Node(int v){
        next = nullptr;
        prev = nullptr;
    }
};

void forwardtraverse(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->value << "<->";
        temp = temp->next;
    }cout << "NULL" << endl;
}

void backwardTraverse(Node* head){
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    while(temp){
        cout << temp->value << "<->";
        temp = temp->prev;
    }cout << "NULL" << endl;
}

bool isPalindrome(Node* head){
    if (head == nullptr || head->next == nullptr){
        return true;
    }
    Node* start = head;
    Node* end = head;
    while(end->next != nullptr){
        end = end->next;
    }
    while(start != nullptr){
        if(start->value != end->value){
            return false;
        }
        start = start->next;
        end = end->prev;
    }
    return true;
}

void reverse(Node* head,Node* tail){
    if(head == nullptr || head->next == nullptr){
        return;
    }
    Node* i = head;
    Node* j = head;
    while(i!=j&&i->prev!=j){
        swap(i->value,j->value);
        i = i->next;
        j = j->next;
    }
}