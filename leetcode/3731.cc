#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.empty()) return{};
        int n = nums.size();
        vector<int> lose;

        int min = *min_element(nums.begin(),nums.end());
        int max = *max_element(nums.begin(),nums.end());
        for(int i = min;i <= max;++i){
            bool fo = false;
            for(int j = 0;j < n;++j){
                if(nums[j] == i){
                    fo = true;
                    break;
                }
            }
            if(!fo){
                lose.push_back(i);
            }
        }      
        return lose;
    }
};