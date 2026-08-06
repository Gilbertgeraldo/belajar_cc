#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S,T;
    cin >> S >> T;
    
    size_t pos;
    while((pos = S.find(T)) != string::npos){
        S.erase(pos,T.length());
    }
    cout << S << endl;
    return 0;
}