#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;


struct Node {
    int data;
    Node* next;

    Node(int val) : data(val),next(nullptr) {}
};

struct LinkedList {
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void tambahDepan(int val) {
        Node* nodebaru = new Node(val);
        nodebaru->next = head;
        head = nodebaru;
    }

    void tambahBelakang(int val) {
        Node* nodebaru = new Node(val);

        if (head == nullptr) {
            head = nodebaru;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodebaru;
    }


    void cetak() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList listku;
    listku.tambahDepan(10);
    listku.tambahDepan(5);
    listku.tambahBelakang(20);
    listku.tambahBelakang(30);

    listku.cetak();

    return 0;
}