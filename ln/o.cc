#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;


void f(int value, int& ref) {
    value++;
    ref++;
    cout << value << endl;
    cout << ref << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cat = 1;
    int dog = 5;

    f(cat,dog);
    cout << cat << endl;
    cout << dog << endl;

    return EXIT_SUCCESS;
}