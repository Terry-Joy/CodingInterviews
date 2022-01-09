/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
// O(n) O(n)
class Solution {
  public:
    ListNode *EntryNodeOfLoop(ListNode *pHead) {
        unordered_map<ListNode *, bool> mp;
        while (pHead) {
            if (mp[pHead]) {
                return pHead;
            } else {
                mp[pHead] = 1;
            }
            pHead = pHead->next;
        }
        return nullptr;
    }
};