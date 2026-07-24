#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int x){
        val = x;
        next = nullptr;
    }
};

int getMiddleElement(Node* head){
    if (head == nullptr || head->next == nullptr){
        return -1;
    }

    Node* slow = head;
    Node* fast = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}