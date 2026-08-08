#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<int>> a(N, vector<int>(M));

    // Input matriks
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    while (X--) {
        string op;
        cin >> op;

        // Refleksi Horizontal (_)
        if (op == "_") {

            vector<vector<int>> temp(N, vector<int>(M));

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    temp[i][j] = a[N - 1 - i][j];
                }
            }

            a = temp;
        }

        // Refleksi Vertikal (|)
        else if (op == "|") {

            vector<vector<int>> temp(N, vector<int>(M));

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    temp[i][j] = a[i][M - 1 - j];
                }
            }

            a = temp;
        }

        // Rotasi 90°
        else if (op == "90") {

            vector<vector<int>> temp(M, vector<int>(N));

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    temp[j][N - 1 - i] = a[i][j];
                }
            }

            a = temp;
            swap(N, M);
        }

        // Rotasi 180°
        else if (op == "180") {

            vector<vector<int>> temp(N, vector<int>(M));

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    temp[N - 1 - i][M - 1 - j] = a[i][j];
                }
            }

            a = temp;
        }

        // Rotasi 270°
        else if (op == "270") {

            vector<vector<int>> temp(M, vector<int>(N));

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    temp[M - 1 - j][i] = a[i][j];
                }
            }

            a = temp;
            swap(N, M);
        }
    }

    // Output
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j];

            if (j != M - 1)
                cout << " ";
        }
        cout << '\n';
    }

    return 0;
}