// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;

//     while (T--) {
//         int n;
//         cin >> n;
//         bool pr = true;
//         if (n < 2)
//             pr = false;
//         for (int i = 2; i * i <= n; i++) {
//             if (n % i == 0) {
//                 pr = false;
//                 break;
//             }
//         }

//         if (pr)
//             cout << "YA\n";
//         else
//             cout << "BUKAN\n";
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s ="ueomusuhamuguluwbyf";
    for(int k =0;k < 26;k++){
        cout << "k = " << k << " : ";
        for(char c : s){
            char re = (c-'a'-k+26)%26+'a';
            cout << re;
        }
        cout <<  "\n";
    }
    return 0;
}