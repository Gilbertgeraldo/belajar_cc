#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
    queue<int> stk;
    MyStack() {

    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        int top = stk.front();
        stk.pop();
        return top;
    }
    
    int top() {
        stk.front();  
    }
    
    bool empty() {
        stk.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */