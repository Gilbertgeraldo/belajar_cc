#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int arr[] = {3,5,7};
    int N = 3;
    int target = 10;
    for(int mask = 0;mask < (1 << N);++mask){ 
        int sum = 0;
        for(int i = 0;i < N;++i){
            if(mask & (1 << i)){
                sum += arr[i];
            }
        }
        if(sum == target){
            cout << "Subset ditemukan ";
            
            for(int i = 0;i < N;++i){
                if(mask & (1 << i)){
                    cout << arr[i] << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}