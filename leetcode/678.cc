#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                count++;
            }
            else if (s[i] == ')') {
                count--;
            }
            else {
                count++;
            }

            if (count < 0)
                return false;
        }

        return (!count == 0);
    }
};