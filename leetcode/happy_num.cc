#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nx(int n) {
        int tot = 0;
        while(n > 0){
            int dg = n % 10;
            tot += pow(dg,2);
            n /= 10;
        }      
        return tot;
    }

    bool isHappy(int n){
        int i = n;
        int j = nx(n);
        while(j != 1 && i != j){
            i = nx(i);
            j = nx(nx(j));
        }
        return j == 1;
    }
};