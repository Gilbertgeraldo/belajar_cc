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

//untuk menjalankan Linked List
void traverse(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->value << "->";
        temp = temp->next;
    }cout << "NULL";
}

// insert node pada awal Linked List
void insertAtHead(Node* head,int v){
  Node* newNode = new Node(v);
  newNode->next = head;
  head = newNode;
}

// insert Node pada akhir Linked List
void insertAtEnd(Node* head,int v){
    if (head == nullptr){
        insertAtHead(head,v);
        return;
    }
    Node* temp = head;
    Node* newNode = new Node(v);
    while(temp->next != nullptr){
        temp= temp->next;
    }
    temp->next= newNode;
}

// insert at Middle pada Linked List
void insertAtMiddle(Node* head,int v,int pos){
    if(pos == 1){
        insertAtHead(head,v);
    }
    Node* newNode = new Node(v);
    Node* prev = head;
    int count = 1;
    while(count < pos - 1){
        prev = prev->next;
        count++;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}

void deleteAtHead(Node* &head){
    if(head == nullptr){
        return;
    }
    Node* temp = head;
    temp = temp->next;
    delete temp;
}

void deleteAtEnd(Node* &head){
    if(head == nullptr){
        return;
    }
    if(head->next == nullptr){
        deleteAtHead(head);
        return;
    }

    Node* secondLast = head;
    while(secondLast->next->next != nullptr){
        secondLast = secondLast->next;
    }

    Node* lNode = secondLast->next;
    secondLast->next = nullptr;
    delete lNode;
}

void insertAtMiddle(Node* head,int pos){
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    Node* prev = head;
    int count = 1;
    while(count < pos - 1){
        prev = prev->next;
    }
    Node* curr = prev->next;
    prev->next = curr->next;
    delete curr;
}

void UpdateNodeValue(Node* head,int v,int pos){
    Node* temp = head;
    int count =1;
    while(count  < pos - 1){
        temp = temp->next;
        count++ ;
    }
    temp->value = v;
}

Node* reverse(Node* head){
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

Node* detectCycle(Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    
    Node* slow = head;
    Node* fast = head;
    Node* entry = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = slow->next->next;
        if(slow  != fast){
            while(slow != entry){
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return nullptr;
}

// untuk menghitung panjang dari sebuah Linked List
int countlen(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

int findMaxVal(Node* head){
    if(head == nullptr) return 0;
    int len = countlen(head);
    int maxval = head->value;
    Node* curr = head;
    for(int i = 1; i <= len;i++){
        if(curr->value > maxval){
            maxval = curr->value;
        }
        curr = curr->next;
    }
    return maxval;
} 

int findMinVal(Node* head){
    if(head == nullptr) return 0;
    int len = countlen(head);
    int minval = head->value;
    Node* curr = head;
    for(int i = 1;i <= len;i++){
        if(curr->value < minval){
            minval = curr->value;
        }
        curr = curr->next;
    }
    return minval;
}

bool isPalindrome(Node* head){
    if(head->next == nullptr){
        return true;
    }

    // find the middle node
    Node* slow = head;
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
    // comparing two linked list
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

// get intersect
Node* intersect(Node* headA,Node* headB){
    if(headA == nullptr && headB == nullptr){
        return nullptr;
    }

    Node* l1 = headA;
    Node* l2 = headB;
    while(l1 != l2){
        if(l1 == nullptr){
            l1 = headB;
        }else if(l2 == nullptr){
            l2 = headA;
        }else{
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    return l1;
}

Node* removeDuplicates(Node* head){
    Node* curr = head;
    if(curr == nullptr && curr->next == nullptr){
        if(curr->value == curr->next->value){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }else{
            curr = curr->next;
        }
    }
    return head;
}
