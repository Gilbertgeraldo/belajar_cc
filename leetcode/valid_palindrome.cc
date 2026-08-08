#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string filt;
        for(char c : s){
            if(isalnum(c)){
                filt += tolower(c);
            }
        }
        int left = 0;
        int right = filt.size() - 1;
        while(left<right){
            if(filt[left] != filt[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};