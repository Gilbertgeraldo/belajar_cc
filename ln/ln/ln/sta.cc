#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    stack<int> mystack;

    for (int i = 0; i < n; i++)
    {
        int c;
        mystack.push(c);
    }

    if (mystack.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }
    cout << "stack size : " << mystack.size() << endl;

    cout << "isi stack : " << endl;

    while(!mystack.empty()) {
        cout << mystack.top() << " ";
        mystack.pop();
    } 
    cout << endl;
    return 0;
}