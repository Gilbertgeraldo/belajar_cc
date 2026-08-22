#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if(head == nullptr){
//         return head;
//        }
//        int c = 0;
//        ListNode* temp = head;
//        while(temp != nullptr){
//         c++;
//         temp = temp->next;
//         }
//         vector<ListNode*> node(c);
//         vector<ListNode*> ans(c);
//         temp = head;
//         for(int i = 0;i < c;++i){
//             node[i] = temp;
//             temp = temp->next;
//         }
//         int idx = 0;
//         for(int i = 0;i < c;i+=2){
//             ans[idx++] = node[i];
//         }
//         for(int i = 1;i < c;i+=2){
//             ans[idx++] = node[i];
//         }
//         for(int i = 0;i < c-1;++i){
//             ans[i]->next = ans[i+1];
//         }
//         ans[c-1]->next = nullptr;
//         return ans[0];
//     }
// };

//2nd solution
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        vector<ListNode*> ls;
        vector<ListNode*> odd;
        vector<ListNode*> even;

        ListNode* temp = head;

        while(temp != nullptr){
            ls.push_back(temp);
            temp = temp->next;
        }
        
        for(int i = 0;i < ls.size();++i){
            if(i % 2 == 0){
                odd.push_back(ls[i]);
            }else{
                even.push_back(ls[i]);
            }

            vector<ListNode*> ans;

            for(auto node : odd){
                ans.push_back(node);
            }
            for(auto node : even){
                ans.push_back(node);
            }
            for(int i = 0;i < ans.size() - 1;++i){
                ans[i]->next = ans[i + 1];
            }
            ans.back()->next = nullptr;
            return ans[0];
        }
    }
};