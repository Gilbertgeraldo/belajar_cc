#include<bits/stdc++.h>
using namespace std;

// ... (Class Node dan fungsi traverse milikmu tetap sama) ...

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
    }cout <<"NULL" << endl;
}
X   
bool isEqual(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->value != temp2->value) return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return (temp1 == NULL && temp2 == NULL);
}

int main() {
    int n = 5;

    // --- MEMBUAT LINKED LIST PERTAMA (1 sampai n) ---
    Node* head1 = NULL;
    Node* tail1 = NULL;
    for (int i = 1; i <= n; i++) {
        Node* newNode = new Node(i);
        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    cout << "Linked List 1: ";
    traverse(head1);

    Node* head2 = NULL;
    Node* tail2 = NULL;
    for (int i = 1; i <= n; i++) {
        Node* newNode = new Node(i);
        if (head2 == NULL) {
            head2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    cout << "Linked List 2: ";
    traverse(head2);

    if (isEqual(head1, head2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    head2->value = 99;
    cout << "\nSetelah LL2 diubah nilainya:" << endl;
    if (isEqual(head1, head2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}