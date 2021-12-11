/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
		vector<ListNode*>ans;
		while(head){
			ans.emplace_back(head);
			head=head->next;
		}
		k--;
		while(k--){
			ans.pop_back();	
		}
		return ans.back();
    }
};