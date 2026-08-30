#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int count = 0;
        stack<int> lo;
        lo.push(-1);
        int n = s.size();
        for(int i = 0;i < n;++i){
            if(s[i] == '('){
                lo.push(i);
            }else{
                lo.pop();

                if(lo.empty()){
                    lo.push(i);
                }else{
                    count = max(count,i - lo.top());
                }
            }
        }
        return count;
    }   
};