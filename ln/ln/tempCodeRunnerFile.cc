#include<bits/stdc++.h>

using namespace std;

int GetMinIdx(const vector<int>& arr, int n) {
    int minIdx = arr[0]; 
    for (int i =1; i < n; i++) {
        if (arr[i] < minIdx) {
            minIdx = i; 
        }
    }
    return minIdx;
}

void selsort(vector<int>& arr) {
    int idx = 0;
    int n = arr.size();

    while (idx < n - 1) {   
        int mid = GetMinIdx(arr, n);
        swap(arr[idx], arr[mid]);
        idx++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) { return 0; }
    vector<int> a(n);
    cout << "Insert the data : " << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Your data : " << endl;
    for (auto x : a) {
        cout << x << "\n";
    }

    selsort(a);

    cout << "Sorted data : " << endl;
    for (auto x : a) {
        cout << x << "\n";
    }

    return 0;
}