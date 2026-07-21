#include<bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0){
        return head;
    }
    ListNode* temp = head;
    int n = 1;
    while(temp->next){
        n++;
        temp = temp->next;
    }

    k = k % n;
    if (k == 0){
        return head;
    }

    temp->next = head;

    temp = head;
    for(int i = 1;i < (n-k);i++){
        temp = temp->next;
    }
    ListNode* newHead = temp->next;

    temp->next = nullptr;
    return newHead;
    }
};