#include<bits/stdc++.h>
using namespace std;

int N;
int a[100];
int countTriples(){
    int count = 0;
    for(int i = 0;i < N;++i){
        for(int j = 1;j < N;++j){
            for(int k = 1;k < N;++k){
                int p = a[i];
                int q = a[j];
                int r = a[k];
                if(p + q + r == 0){
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    cin >> N;
    for(int i = 0;i < N;++i){
        cin >> a[i];
    }
    int res = countTriples();
    cout << "Jumlah triplet " << res << endl;
    return 0;   
}