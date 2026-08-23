#include<bits/stdc++.h>
using namespace std;

const int SIZE = 7;
struct Node{
    int key;
    string value;
    Node* next;

    Node(int k,string v){
        value = v;
        key = k;
        next = nullptr;
    }
};

class HashTable{
    private:
        Node* table[SIZE];
        int hashfunction(int key){
            return key % 7;
        }
    public:
        HashTable(){
            for(int i = 0;i < SIZE;++i){
                table[i] = nullptr;
            }
        }

        void insert(int key,string value){
            int idx = hashfunction(key);
            Node* New = new Node(key,value);
            New->next = table[idx];
            table[idx] = New;
        }

        void search(int key){
            int idx = hashfunction(key);

            Node* curr = table[idx];
            while(curr){
                if(curr->key == key){
                    cout << "Ditemukan : " << curr->value << endl;
                    return;
                }
                curr = curr->next;
            }
            cout << "Data tidak ditemukan\n";
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
                    cout << "Data berhasil dihapus\n";
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            cout << "Data tidak ada\n";
        }

        void display(){
            for(int i = 0;i < SIZE;++i){
                cout << "[" << i << "]";

                Node* curr = table[i];

                while(curr){
                    cout << "(" << curr->key << "," << curr->value << ")";
                    curr = curr->next;
                }
            }
        }
};

int main(){

}