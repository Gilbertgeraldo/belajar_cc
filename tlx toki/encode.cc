#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;

    getline(cin, s);   // Input kalimat
    cin >> k;          // Nilai pergeseran

    for (char c : s) {

        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + k) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + k) % 26 + 'A';
        }

        cout << c;
    }

    return 0;
}