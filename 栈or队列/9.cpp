class CQueue {
    stack<int> st1;
    stack<int> st2;

  public:
    CQueue() {}

    void appendTail(int value) { st1.push(value); }

    int deleteHead() {
        if (!st1.size() && !st2.size())
            return -1;
        else if (!st2.size()) {
            while (st1.size()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ans = st2.top();
        st2.pop();
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */