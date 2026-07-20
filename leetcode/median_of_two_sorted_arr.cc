#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){
            if (nums1.size() > nums2.size()){
                return findMedianSortedArrays(nums2,nums1);
            }

            int m = nums1.size();
            int n = nums2.size();

            int low = 0;
            int high = m;
            int totalLeft = (m + n + 1)/2;

            while(low <= high){
                int part1 = low + (high-low) / 2;
                int par2 = totalLeft - part1;

                int ml1;
                if (part1 == 0){
                    ml1 = INT_MIN;
                }else{
                    ml1 = nums1[part1-1];
                }

                int mr1;
                if (part1 == m){
                    mr1 = INT_MAX;
                }else{
                    mr1 = nums1[part1];
                }

                int ml2;
                if (par2 == 0){
                    ml2 = INT_MIN;
                }else{
                    ml2 = nums2[par2-1];
                }
                
                int mr2;
                if (par2 == m){
                    mr2 = INT_MAX;
                }else{
                    mr2 = nums2[par2];
                }

                if (ml1 <= mr2 && ml2 <= mr1){
                    if ((m + n) % 2 == 1) {
                        return max(ml1,ml2);
                    }else {
                        return (max(ml1,ml2) + min(mr1,mr2)) / 2.0;
                    }
                }else if (ml1 > mr2){
                    high = part1 - 1;
                }else{
                    low = part1+1;
                }
            }
            return 0.0;
        }
};