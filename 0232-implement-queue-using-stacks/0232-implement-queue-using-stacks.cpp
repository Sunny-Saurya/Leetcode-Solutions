class MyQueue {
public:
stack<int>in, ot;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(ot.empty()){
            while(!in.empty()){
                ot.push(in.top());
                in.pop();
            }
        }
        int x = ot.top();
        ot.pop();
        return x;
    }
    
    int peek() {
         if(ot.empty()){
            while(!in.empty()){
                ot.push(in.top());
                in.pop();
            }
        }
        return ot.top();
    }
    
    bool empty() {
        return in.empty() && ot.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */