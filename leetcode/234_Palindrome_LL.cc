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
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) {
            return true;
        }

        //find the middle node in LL
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse the ll
        ListNode* curr = slow;
        ListNode* prev = NULL;
        ListNode* next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //comparing the two half of the LL
        ListNode* head2 = prev;
        while(head2) {
            if(head->val != head2->val) {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};