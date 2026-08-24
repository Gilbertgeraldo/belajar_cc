#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int rand7(){
            return 1 + rand() % 7;
        }
        int rand10(){
            int row = rand7();
            int col = rand7();
            int idx = (row-1) * 7 + col;

            if(idx <= 40){
                return 1 + (idx-1) % 10;
            }
        }
};