#include <iostream>
using namespace std;

const int SIZE = 11;

struct Node{
    int key;
    string value;
    Node* next;

    Node(int k, string v){
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable{
private:
    Node* table[SIZE];

    int hashFunction(int key){
        return key % SIZE;
    }

public:
    HashTable(){
        for(int i = 0; i < SIZE; i++)
            table[i] = nullptr;
    }

    void insert(int key, string value){
        int idx = hashFunction(key);

        Node* baru = new Node(key, value);
        baru->next = table[idx];
        table[idx] = baru;
    }

    void search(int key){
        int idx = hashFunction(key);

        Node* cur = table[idx];

        while(cur){
            if(cur->key == key){
                cout << "Ditemukan : " << cur->value << endl;
                return;
            }
            cur = cur->next;
        }

        cout << "Data tidak ditemukan\n";
    }

    void remove(int key){
        int idx = hashFunction(key);

        Node* cur = table[idx];
        Node* prev = nullptr;

        while(cur){
            if(cur->key == key){

                if(prev == nullptr)
                    table[idx] = cur->next;
                else
                    prev->next = cur->next;

                delete cur;
                cout << "Data berhasil dihapus\n";
                return;
            }       

            prev = cur;
            cur = cur->next;
        }

        cout << "Data tidak ada\n";
    }

    void display(){
        for(int i = 0; i < SIZE; i++){
            cout << "[" << i << "] : ";

            Node* cur = table[i];

            while(cur){
                cout << "(" << cur->key << "," << cur->value << ") -> ";
                cur = cur->next;
            }

            cout << "NULL\n";
        }
    }
};

int main(){

    HashTable ht;

    ht.insert(21,"Gilbert");
    ht.insert(32,"Budi");
    ht.insert(43,"Sinta");
    ht.insert(54,"Andi");

    cout << "Isi Hash Table\n";
    ht.display();

    cout << endl;

    ht.search(32);

    ht.remove(32);

    cout << endl;

    ht.display();

    return 0;
}