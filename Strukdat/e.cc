#include<bits/stdc++.h>
using namespace std;

int main(){
   int N;
   cin >> N;
   int genap = N/2;
   int ganjil = N - genap;

   double ans = double(ganjil)/N;
   cout << fixed << setprecision(3) << ans << endl;
    return 0;
}