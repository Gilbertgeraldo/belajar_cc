#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair

// int hitung_vokal(string s) {
//     if (s.empty()) {return 0;}

//     char c = tolower(s[0]);
//     bool isVokal = (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');

//     if (isVokal) {
//         return 1 + hitung_vokal(s.substr(1));
//     }else {
//         return 0 + hitung_vokal(s.substr(1));
//     }
// }

// int main() {
//     cout << hitung_vokal("lorem ipsum dolor sit amet fermentum egestas luctus praesent torquent justo.") << endl;
//     return 0;
// }

// bool palindrom(string s) {
//     if (s.length() <= 1) {
//         return true;
//     }else {
//         return false;
//     }

//     if (s[0] != s.length() -1) {
//         return false;
//     }

//     return palindrom(s.substr(1,s.length() - 2));
// }

// bool pali(string s) {
//     string res = s;
//     reverse(s.begin(),s.end());
//     return res == s;  
//}

int main() {
    string password = "kominfo ea";

    if (password.empty()) {
        cout << "password tidak boleh kosong" << endl;
        return 0;
    }

    int kecil = 0;
    int besar = 0;
    int angka = 0;
    int simbol = 0;

    for (char karakter : password) {
        if (isalpha(karakter)) {
            if (isupper(karakter)) {
                besar++;
            }else if (islower(karakter)){
                kecil++;
            } else if (isdigit(karakter)) {
                angka++;
            }else {
                simbol++;
            }
        }
    }
    cout << "String : " << password << endl;
    cout << "panjang : " << password.length() << endl;
    cout << "---------------------------------------------" << endl;
    cout << "besar : " << besar << endl;
    cout << "kecil : " << kecil << endl;
    cout << "angka : " << angka << endl;
    cout << "simbol : " << simbol << endl;
    return 0;
}