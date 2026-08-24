#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* child_tail = curr->child;
                while (child_tail->next != nullptr) {
                    child_tail = child_tail->next;
                }
                if (curr->next != nullptr) {
                    child_tail->next = curr->next;
                    curr->next->prev = child_tail;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            curr = curr->next;
        }

        return head;
    }
};