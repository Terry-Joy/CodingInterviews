//一个栈实现 内部为 先前最小值 当前top 先前最小值 当前top, mn记录现在最小值
//O(n) O(n)
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    int mn = INT_MAX; //
    MinStack() {

    }
    
    void push(int x) {
        st.push(mn);
        if(!st.size() || x <= mn)
            mn = x;
        st.push(x);
	}
    void pop() {
        st.pop();
        mn = st.top();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int min() {
        return mn;
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