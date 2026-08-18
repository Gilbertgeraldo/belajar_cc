#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
    public:
        ListNode* reverseBetween(ListNode* head,int left,int right){
            if(head == nullptr || head->next == nullptr){
                return head;
            }
            while(left <= right){
                ListNode* i = head;
                ListNode* j = head;
                for(int p = 1;p < left;++p){
                    i = i->next;
                }
                for(int p = 1;p < right;++p){
                    j = j->next;
                }
                swap(i->val,j->val);
                left++;
                right--;
            }
            return head;
        }
};