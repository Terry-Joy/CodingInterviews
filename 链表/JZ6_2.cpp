/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
		vector<int>res;
		while(head!=NULL) {
			result.push_back(head->val);
			head=head->next;
		}
		while(!result.empty()){
			res.push_back(result.back());
			result.pop_back();
		}
		return res;
    }
};