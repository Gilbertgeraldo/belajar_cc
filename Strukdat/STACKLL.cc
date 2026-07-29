#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> a;

    a.push(2);
    a.push(3);
    a.push(4);

    cout << a.size() << endl;
    cout << "Top element : " << a.top() << endl;
    cout << "Removing the top element" << endl;
    a.pop();
    cout << "The top element after popping" << a.top() << endl;
    a.pop();
    cout << "After popping" << a.top() << endl;
    
    cout << a.empty() << endl;

    return 0; 
}