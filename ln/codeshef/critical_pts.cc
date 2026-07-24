#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int solve(Node* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return 0;
    }

    int count = 0 ;
    Node* prev = head;
    Node* curr = head->next;
    Node* next = curr->next;

    while(next != nullptr) {
        //local maximum
        if (curr->data > prev->data && curr->data < next->data) {
            count++;
        }
        //locak minimum
        if (curr->data < prev->data && curr->data < next->data) {
            count++;
        }

        prev = curr;
        curr = next;
        next = next->next;
    }
    return count;
}