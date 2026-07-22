#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node* prev;

    Node(int v){
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtHead(Node* &head,int v){
    Node* newNode = new Node(v);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
}

void insertAtEnd(Node* head,int v){
    Node* newNode = new Node(v);
    if(head == nullptr){
        insertAtHead(head,v);
        return;
    }
    Node* lastNode = head;
    while(lastNode->next != nullptr){
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void reverseLL(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

bool isPalindrome(Node* head){
    if(head->next == nullptr){
        return true;
    }

    //find the middle node
    Node* slow =  head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    //reverse
    Node* curr = slow;
    Node* prev = nullptr;
    Node* next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //comparing the two half of ll
    Node* head2 = slow;
    while(head2){
        if(head->value != head2->value){
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    return true;
}

void rotateByK(Node* &head,int k){
    Node* temp = head;
    int n = 1;
    while(temp->next != nullptr){
        n++;
        temp = temp->next;
    }
    //temp is pointing to last node
    k = k % n;
    if(k == 0)return;
    temp->next = head;

    //find the n-k node
    temp = head;
    for(int i = 1;i < (n - k);++i){
        temp = temp->next;
    }
    Node* newHead = temp->next;
    temp->next = nullptr;
    head = newHead;
}

int Middle(Node* head){
    if(head->next == nullptr){
        return head->value;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}

//doubly linked list
void insertLL(Node* &head,int v){
    Node* newNode = new Node(v);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertEnd(Node* head,int v){
    Node* newNode = new Node(v);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* lastNode = head;
    while(lastNode->next != nullptr){
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

void Imiddle(Node* head,int v,int p){
    if(p == 1){
        insertAtHead(head,v);
        return;
    }
    Node* temp = head;
    for(int i = 1;i <(p-1);++i){
        temp = temp->next;
    }
    Node* newNode = new Node(v);
    if(temp->next != nullptr){
        temp->next->prev = newNode; //ibaratkan 1->2 tapi dia harus dimundurkan dan diganti oleh newnode,misal 1->2,temp = head <=> temp = 1;temp.next = 2; temp.next.prev = newnode == 1->newnode->2
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void delen(Node* head,int pos){
    if(pos == 1)return;
    if(head == nullptr) return;
    Node* temp = head;
    for(int i = 1;i < pos;i++) temp = temp->next;
    Node* delNode = temp->next;
    temp->next = delNode->next;
    if(delNode->next != nullptr) delNode->next->prev = temp;
    delete delNode;
}