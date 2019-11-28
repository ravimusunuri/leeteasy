class element {
    public:
        int val;
        int min;
};

class MinStack {
public:
    stack<element> stk;
    
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        int cur;
        if (!stk.empty() ) {
            element top = stk.top();
            cur = top.min;
        }  else {
            cur = x;
        }
    
        element tmp;
        tmp.val = x;
        tmp.min = min(cur, x);
        stk.push(tmp);
    }
    
    void pop() {
        if (!stk.empty())
            stk.pop();
    }
    
    int top() {
        if (!stk.empty()) {
            element top = stk.top();
            return (top.val);
        } else {
            return -1;
        }
    }
    
    int getMin() {
        if (!stk.empty()) {
           element top = stk.top();
           return (top.min);
         } else {
            return -1;
         }
    }
};
