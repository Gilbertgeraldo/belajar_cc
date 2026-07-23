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

void addHead(Node* head,int v){
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

void addEnd(Node* head,int v){
    Node* temp = head;
    Node* lastNode = new Node(v);
    if(head == nullptr){
        head = lastNode;
        return;
    }
    while(lastNode->next != nullptr){
        temp = temp->next;
    }
    lastNode->next = temp;
}

int countlen(Node* head){
    int c = 0;
    Node* temp = head;
    while(temp != nullptr){
        temp = temp->next;
        c++;
    }
    return c;
}

int findMaxVal(Node* head){
    if(head == nullptr) return 0;

    Node* curr = head;
    int maxval = head->value;
    int len = countlen(head);
    for (int i = 1;i <= len;++i){
        if(curr->value > maxval){
            maxval = curr->value;
        }
        curr = curr->next;
    }
    return maxval;
}

int findMinVal(Node* head){
    if(head == nullptr) return 0;

    Node* curr = head;
    int minVal = head->value;
    int len = countlen(head);
    for(int i = 1;i <= len;++i){
        if(curr->value < minVal){
            minVal = curr->value;
        }
        curr = curr->next;
    }
    return minVal;
}

Node* getNodeAt(Node* head, int idx) {
    Node* curr = head;
    for(int i = 1;i < idx && curr != nullptr;++i){
        curr = curr->next;
    }
    return curr;
}

void insertsort(Node* head){
    if(head == nullptr) return;
    int sub =0;
    int clen = countlen(head);
    while(sub < clen - 1){
        int ins = sub + 1;
        int t = sub;

        while(t >= 0){
            Node* left = getNodeAt(head,t);
            Node* right = left->next;

            if(left != nullptr && right  !=  nullptr && left->value > right->value){
                swap(left->value,right->value);
                ins--;
                t--;
            }else{
                break;
            }
        }
        sub++;
    }
}

bool ispalindrome(Node* head){
    if(head->next == nullptr){return true;}

    //find the middle node
    Node* slow =head; 
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //reverse the linked list
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //comparing the two half in linked list
    Node* head2 = prev;
    while(head2){
        if(head->value != head2->value){
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    return true;
}