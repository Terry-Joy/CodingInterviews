//辅助栈 O(n) O(1) 
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st1, st2;
    MinStack() {

    }
    
    void push(int x) {
        st1.push(x);
		if (st2.empty() || x <= st2.top()) {
			st2.push(x);
		}
	}
    void pop() {
        if(st2.top() == st1.top())
            st2.pop();
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int min() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */