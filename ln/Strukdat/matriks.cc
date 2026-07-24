#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vector<vector<int>> matriks(N,vector<int>(M));
    for (int i = 0;i < N;++i) {
        for (int j = 0;j < N;++j) {
            cin >> matriks[i][j];
        }
    }

    for (int i = 0;i < N;++i) {
        for (int j = 0;j < N;++j) {
            cout << matriks[N-1-j][i];
            if (j < N -1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}