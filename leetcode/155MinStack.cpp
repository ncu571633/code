 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.



class MinStack {
private:
    stack<int> s;
    stack<int> smin;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(smin.empty() || smin.top()>=x)
            smin.push(x);
    }
    
    void pop() {
        if(s.top()==smin.top())
            smin.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return smin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 
class MinStack {
private:
    stack<int> s;
    stack<int> smin;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(smin.empty() || smin.top()>=x)
            smin.push(x);
    }
    
    void pop() {
        if(s.empty())
            return ;
        if(s.top() == smin.top()) 
            smin.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return smin.top();
    }
}; 
 
class MinStack {
private:
    stack<int> s;
    stack<pair<int, int>> smin;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(smin.empty()) {
            smin.push({x, 1});
        } else {
            if(smin.top().first==x)
                smin.top().second++;
            if(smin.top().first>x)
                smin.push({x, 1});
        }
    }
    
    void pop() {
        if(s.top()==smin.top().first)
        {
            smin.top().second--;
            if(smin.top().second==0)
                smin.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return smin.top().first;
    }
};
