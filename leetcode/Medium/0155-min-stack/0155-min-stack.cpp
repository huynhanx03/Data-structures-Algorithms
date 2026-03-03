/*
 Problem: 155. Min Stack
 Language: cpp
 Runtime: 16 ms (6.37%)
 Memory: 21.4 MB (99.98%)
 Tags: Stack, Design
*/
class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
        int mn;

        if (st.empty()) {
            mn = val;
        } else {
            mn = min(val, this->getMin());
        }

        st.push({val, mn});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.empty() ? -1 : st.top().first;
    }
    
    int getMin() {
        return st.empty() ? -1 : st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */