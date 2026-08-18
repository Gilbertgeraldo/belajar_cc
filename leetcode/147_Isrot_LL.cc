#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* temp = head;
        int sub = 0;
        int c = 0;
        while(temp != nullptr){
            c++;
            temp = temp->next;
        }
        vector<ListNode*> nodes(c);
        temp = head;
        for(int i = 0;i < c;i++){
            nodes[i] = temp;
            temp = temp->next;
        }
        while(sub < c -1){
            int ins = sub + 1;
            int t = sub;
            while(t>=0){
                ListNode* a = nodes[ins];
                ListNode* b = nodes[t];
                if(a == nullptr || b == nullptr || a->val >= b->val){
                    break;
                }
                swap(a->val,b->val);
                ins--;
                t--;
            }
            sub++;
        }
        return head;
    }
};