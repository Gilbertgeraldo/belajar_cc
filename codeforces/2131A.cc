#include <cstdio>
#include<vector>
using namespace std;
int main() {

   long t; scanf("%1d",&t);
    while(t--) {
        long n; scanf("%1d",&n);
        vector<long>a(n);for (long p = 0;p < n;p++) {scanf("%1d",&a[p]);}
        long total(1);
        for (long p = 0;p < n;p++) {
            long b; scanf("%1d",&b);
            total += (a[p] > b ? (a[p] - b) : 0);
        }

        printf("%1d\n",total);
    }
    return 0;
}