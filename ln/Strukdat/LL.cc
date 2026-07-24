#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = NULL;
    }
};

void traverse(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next;
    }cout << "NULL" << endl;
}

void insertAtHead(Node* &head,int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode; 
}

void insertAtEnd(Node* &head,int val) {
    if (head == NULL) {
        insertAtHead(head,val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next != NULL) {
        temp =  temp->next;
    }
    // temp now is pointing to the ending of node
    temp->next = newNode;
}

void reverseLL(Node* &head) {
    Node* prev = NULL;
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

bool isEq(Node* head1,Node* head2) {
    while(head1 && head2) {
        if (head1->value != head2->value) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL || head2 == NULL);
}

bool isPalindrome(Node* head) {
    if(head->next == NULL) {
        return true;
    }

    //find the middle node  
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    //reverse
    Node* curr = slow;
    Node* prev = NULL;
    Node* next;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //comparing the two half of the linked list
    Node* head2 = prev;
    while(head2) {
        if (head->value != head2->value) {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    return true; 
}

void rotateByK(Node* &head,int k) {
    Node* temp = head;
    int n = 1;
    while(temp->next) {
        n++;
        temp = temp->next;
    }
    //temp is pointing to last node
    k = k % n;
    if (k == 0) return;
    // make last node point to head
    temp ->next = head;

    //find the n-k node
    temp = head;
    for (int i = 1;i < (n-k);n++) {
        temp = temp->next;
    }
    Node* newHead = temp->next; //(n-k+1) node

    //make n-k point to NULL
    temp->next = NULL;

    head = newHead;
}

Node* mergeLL(Node* head1,Node* head2) {
    Node* DummyHead = new Node(-1);
    Node* head3 = DummyHead;

    while(head1 && head2) {
          if (head1->value < head2->value) {
        head3->next = head1;
        head1 = head1->next;
        }else {
            head3->next = head2;
            head2 = head2->next;
        }
        head3 = head3->next;
    }

    if (head1) {
        head3->next = head1; 
    }
    if(head2) {
        head3->next = head2;
    }

    return DummyHead->next; 
}

int main() {
    Node* head = NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    // insertAtHead(head,1);
    // insertAtHead(head,3);
    // insertAtHead(head,3);
    // insertAtHead(head,1);
    traverse(head);
    reverseLL(head);
    traverse(head);
    cout << isPalindrome(head) << endl;
    rotateByK(head,2);
    traverse(head);
}