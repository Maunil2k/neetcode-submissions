class MinStack {
private: 
    stack<int> main_stack;
    stack<int> min_stack;

public:
    MinStack() {}
    
    void push(int val) {
        if (main_stack.empty() || val < min_stack.top()) {
            main_stack.push(val);
            min_stack.push(val);
        }
        // else if (val < min_stack.top()) {
        //     min_stack.push(val);
        //     main_stack.push(val);
        // }
        else {
            min_stack.push(min_stack.top());
            main_stack.push(val);
        }
    }
    
    void pop() {
        main_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
