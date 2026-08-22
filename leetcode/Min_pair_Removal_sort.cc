#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPair(const vector<long long>& v) {
        long long mn = LLONG_MAX;
        int pos = 0;

        for (int i = 0; i < v.size() - 1; i++) {
            long long sum = v[i] + v[i + 1];
            if (sum < mn) {
                mn = sum;
                pos = i;
            }
        }
        return pos;
    }

    void mergePair(vector<long long>& v, int pos) {
        v[pos] += v[pos + 1];
        v.erase(v.begin() + pos + 1);
    }

    int minimumPairRemoval(vector<int>& nums) {
        vector<long long> v(nums.begin(), nums.end());

        int ans = 0;
        while (!is_sorted(v.begin(), v.end())) {
            mergePair(v, minPair(v));
            ans++;
        }
        return ans;
    }
};
