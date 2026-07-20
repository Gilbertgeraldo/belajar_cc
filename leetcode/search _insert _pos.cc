#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert1(vector<int>& nums, int target) {
        int l = 0,h = nums.size()-1;
        while(l <= h){
            int m = l + (h - l)/2;
            if (nums[m] == target){
                return m;
            }
            if(target < nums[m]){
                h = m - 1;
            }else{
                l = m +1;
            }
        }
        return l;
    }

    int searchInsert(vector<int>& nums,int target){
        return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    }
};