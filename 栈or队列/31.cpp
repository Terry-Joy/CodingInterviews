//O(n) O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> st;
        int i = 0, j = 0, len = pushed.size();
        while (j < len) {
            st.push_back(pushed[j++]);
            while(!st.empty() && st.back() == popped[i]) {
                st.pop_back();
                i++;
            }
        }
        return st.empty();
    }
};