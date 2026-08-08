#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int v)
    {
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

void forwartTraversal(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->value << "<->";
        temp = temp->next;
    }
    cout << "NULL";
}

void backwardTraversal(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    while (temp)
    {
        cout << temp->value << "<->";
        temp = temp->prev;
    }
    cout << "NULL";
}

void insertAtStart(Node *head, int v)
{
    Node *newNode = new Node(v);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node *head, int v)
{
    Node *newNode = new Node(v);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *lastNode = head;
    while (lastNode->next != nullptr)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

void insertAtMiddle(Node *head, int v, int pos)
{
    if (pos == 1)
    {
        insertAtStart(head, v);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(v);
    if (temp->next)
    {
        temp->next->prev = newNode;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtStart(Node *&head)
{
    if (head->next == nullptr)
    {
        delete head;
        return;
    }
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

void deleteAtEnd(Node *&head)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *lastNode = temp->prev;
    lastNode->next = nullptr;
    delete lastNode;
}

void reverse(Node* head,Node* tail){
    if(head == nullptr || head->next == nullptr){
        return;
    }
    Node* i = head;
    Node* j = head;
    while(i != j && i->prev != j){
        swap(i->value,j->value);
        i = i->next;
        j = j->next;
    }
}

bool is_palindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }
    Node *start = head;
    Node *end = head;
    while (end->next != nullptr)
    {
        end = end->next;
    }
    while (start != nullptr)
    {
        if (start->value != end->value)
        {
            return false;
        }
        start = start->next;
        end = end->prev;
    }
    return true;
}

int countlen(Node *head)
{
}