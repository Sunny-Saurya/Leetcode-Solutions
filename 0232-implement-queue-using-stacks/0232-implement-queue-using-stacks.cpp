#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;

    void transfer() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        transfer();
        if (outStack.empty()) return -1; // queue empty
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        transfer();
        if (outStack.empty()) return -1;
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
