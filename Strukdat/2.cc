#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int knapsack(int W,vector<int>& wt,vector<int>& val,int n) {
    vector<vector<int>> dp(n+1,vector<int>(W + 1,0));

    for (int i = 1;i <= n;i++) {
        for (int w = 0;w <= W;w++) {
            dp[i][w] = dp[i-1][w];
            if (wt[i-1] <= w) {
                dp[i][w] = max(dp[i][w],dp[i-1][w-wt[i-1]] + val[i-1]);
            }
        }
    }
    return dp[n][W];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W = 6;
    vector<int> wt = {1,3,4,5};
    vector<int> val = {2,4,6,7};
    
    int n = wt.size();
    cout << knapsack(W,wt,val,n);

    return 0;
}