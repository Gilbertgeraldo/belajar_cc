#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int v){
        value = v;
        next = nullptr;
    }
};

class Solution{
    public:
        Node* removeDuplicates(Node* head){
            if(head == nullptr || head->next == nullptr){
                return head;
            }

            Node* curr = head;
            while(curr != nullptr && curr->next != nullptr){
                if(curr->value == curr->next->value){
                    Node* temp =curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                }else{
                    curr = curr->next;
                }
            }
            return head;
        }
    };

int solve(Node* head){
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
        return 0;
    }

    int count = 0;
    Node* prev = head;
    Node* curr = head->next;
    Node* next = curr->next;

    while(next != nullptr){
        //local maximum
        if(curr->value > prev->value && curr->value < prev->value){
            count++;
        }
        //minimum
        if(curr->value < prev->value && curr->value < next->value){
            count++;
        }

        prev = curr;
        curr = next;
        next = next->next;
    }
    return count;
}