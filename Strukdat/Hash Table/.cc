#include<bits/stdc++.h>
using namespace std;

const int SIZE = 5;

class Node{
    public:
    int key;
    string value;
    Node* next;

    Node(int k,string v){
        key = k;
        value = v;
        next = nullptr;
    }
};

class Hashtable{
    private:
        Node* table[SIZE];
        int hashfunction(int key){
            return key % SIZE;
        }
    public:
        Hashtable(){
            for(int i = 0;i < SIZE;++i){
                table[i] = nullptr;
            }
        }

        void insert(int key,string value){
            int idx = hashfunction(key);

            Node* ne = new Node(key,value);
            ne->next = table[idx];
            table[idx] = ne;
        }

        void search(int key){
            int idx = hashfunction(key);
            Node* curr = table[idx];
            
            while(curr){
                if(curr->key == key){
                    cout << "Data ditemukan\n" << curr->value;
                    return;
                }
                curr = curr->next;
            }
            cout << "Data tidak ditemukan.\n";
        }

        void remove(int key){
            int idx = hashfunction(key);

            Node* temp = table[idx];
            Node* prev = nullptr;
            while(temp){
                if(temp->key == key){
                    if(prev == nullptr){
                        table[idx] = temp->next;
                    }else{
                        prev->next = temp->next;
                    }
                    delete temp;
                    cout << "Data berhasil dihapus.\n";
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            cout << "Data tidak ditemuka.\n";
        }

        void display(){
            for(int i = 0;i < SIZE;++i){
                cout << "[" << i << "]" << endl;

                Node* curr = table[i];
                while(curr){
                    cout << "(" << curr->key << "," << curr->value << ")";
                    curr = curr->next;
                }
            }
        }
};