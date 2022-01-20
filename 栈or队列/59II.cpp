//单调队列 O(1)
class MaxQueue {
public:
    queue<int> q;
    deque<int> dq;
    MaxQueue() {

    }
    
    int max_value() {
        if(dq.empty())
            return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        while(!dq.empty() && dq.back() < value)
            dq.pop_back();
        dq.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int now = q.front();
        if (now == dq.front()) {
           dq.pop_front(); 
        }
        q.pop();
        return now;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */