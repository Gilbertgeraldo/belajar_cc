#include<bits/stdc++.h>

using namespace std;

int search(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    int m = left + (right - left) /2;

    if (arr[m] == target) { 
        return m;
    }

    if (arr[m] > target) { 
        left = m + 1;
    }else {
        right = m - 1;
    }
    return -1;
}

int main() {
    vector<int> a;
    int n,vtr;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukan nilai ke : " << i + 1,cin >> vtr;
        a.push_back(vtr);
    }

    sort(a.begin(),a.end());

    cout << "data anda setelah diurutkan : " << endl;
    for (auto value : a) {
        cout << value << " ";
    }
    cout << endl;

    int target;
    cout << "Masukan angka target : ", cin >> target;

    int res = search(a,target);

    if (res != -1) {
        cout <<"Angka anda ditemukan pada index ke-" << res << endl;
    }else {
        cout << "Angka anda tidak ditemukan dalam vector!" << endl;
    }
    return 0;
}