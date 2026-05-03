#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main() {
    vector<string>nama;

    nama.push_back("agape");
    nama.push_back("budi");
    nama.push_back("caca");

    nama[1] = "Deni";

    for (auto orang : nama) {
        cout << orang << " ";
    }
    
    
}