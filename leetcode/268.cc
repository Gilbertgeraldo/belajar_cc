#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
       int tot = n * (n + 1)/2;
       int sum = 0;
       for(int x : nums){
        sum += x;
       }
       return tot - sum;
    }
};