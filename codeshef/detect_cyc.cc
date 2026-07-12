#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
    public:
    Node* detectCycle(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        Node* slow = head;
        Node* fast = head;
        Node* entry = head;

        while(fast && fast->next){ 
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};