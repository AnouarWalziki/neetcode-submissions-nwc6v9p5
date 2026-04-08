class MinStack {
public:
    stack<int> vals;
    stack<int> mins;

    MinStack() {
        
    }
    
    void push(int val) {
        vals.push(val);
        if(mins.empty() || (mins.top() >= val))
            mins.push(val);
    }
    
    void pop() {
        if(mins.top() == vals.top())
            mins.pop();
        vals.pop();
    }
    
    int top() {
        return vals.top();
    }
    
    int getMin() {
        return mins.top();
    }


};
