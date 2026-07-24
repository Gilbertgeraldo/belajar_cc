#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

int getLength(Node* head) {
    int lco = 0;
    if (head == nullptr) {
        return 0;
    }

    Node* temp = head;
    while(temp != nullptr) {
        lco++;
        temp = temp->next;
    }
    return lco;
}