class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    int topVal;
public:
    MyStack() {}
    
    void push(int x) {
        if (q1.empty() && q2.empty()) q1.push(x);
        else if (q1.empty()) q2.push(x);
        else q1.push(x);
        topVal = x;
    }
    
    int pop() {
        if (q1.empty()) {
            while(q2.size() != 1) {
                q1.push(q2.front());
                topVal = q2.front();
                q2.pop();                
            }
            int res = q2.front();
            q2.pop();
            return res;
        }

        else {
            while(q1.size() != 1) {
                q2.push(q1.front());
                topVal = q1.front();
                q1.pop();
            }
            int res = q1.front();
            q1.pop();
            return res;
        }
    }
    
    int top() {
        return topVal;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
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