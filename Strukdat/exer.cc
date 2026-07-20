#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int v){
        value = v;
        next = nullptr;
    }
};

void traverse(Node* head){
    Node* temp = head;
    while(temp != nullptr){ 
        cout << temp->value <<" -> ";
        temp = temp->next;
    }cout << "NULL" << endl;
}

void InsertatHead(Node* &head,int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_node(Node* &head,int n){
    for (int i = 0;i < n;i++){\
        Node* new_node = new Node(i);
        if(head == nullptr){
            head = new_node;
        }else{
            Node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
}

Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int CountList(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp->next != nullptr) {
        cnt++; 
        temp = temp->next;
    }
    return cnt;
}

void insertAtEnd(Node* head,int val){
    if (head ==nullptr){
        InsertatHead(head,val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

int MiddleList(Node* head){
    if (head == nullptr && head->next == nullptr){
        return -1;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}

Node* mergeLL(Node* head1,Node* head2){
    Node* dunmyHead = new Node(-1);
    Node* Node3 = dunmyHead;

    while(head1 && head2){
        if (head1->value < head2->value){
            Node3->next = head1;
            head1 = head1->next;
        }else{
            Node3->next = head2;
            head2 = head2->next;
        }
        Node3 = Node3->next;
    }

    if(head1){
        Node3->next = head1;
    }
    if(head2){
        Node3->next = head2; 
    }
    return dunmyHead->next;
}

void InsertAtEnd(Node* head,int v){
    if (head == nullptr){
        InsertatHead(head,v);
        return;
    }
    Node* temp = head;
    Node* newNode = new Node(v);
    while(temp->next != nullptr){
        temp = temp->next;
    }
    // temp sekarang pointing ke node terakhir
    temp->next = newNode;
}

void InsertAtMiddle(Node* head,int v,int pos){
    if (pos == 1){
        InsertatHead(head,v);
    }

    Node* newNode = new Node(v);
    Node* prev = head;
    int count = 1;
    while(count < (pos-1)){
        prev = prev->next;
        count++;
    }
    newNode->next = prev->next;
    prev->next = newNode;  
}

int GetLLValues(Node* head,int pos){
  if (pos == 1){
    return head->value;
  }
  if (head == nullptr){
    return -1;
  }

  int count = 1;
  Node* temp = head;
  Node* newNode = head;

  while(temp->next != nullptr){
        temp = temp->next;
        count++;

        if (count == pos){
            newNode = temp;
            break;
        }
    }
    return newNode->value;
}

void deleteAtHead(Node* &head){
    if(head == nullptr){
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(Node* &head){
    if (head == nullptr){
        return;
    }
    if (head->next == nullptr){
        deleteAtHead(head);
        return;
    }
    Node* secondLast = head;
    while(secondLast->next->next!= nullptr){
        secondLast = secondLast->next;
    }

    Node* lastNode = secondLast->next;
    secondLast->next = nullptr;
    free(lastNode);
}

int main(){
    Node* head = nullptr;
    insert_node(head,5);
    head = reverseList(head);
    traverse(head);
    cout << CountList(head) << endl;
    InsertatHead(head,50);
    traverse(head);
    insertAtEnd(head,43);
    traverse(head);
    cout << CountList(head) << endl;
    cout << MiddleList(head) << endl;
    InsertAtEnd(head,6);
    traverse(head);
    return 0;
}