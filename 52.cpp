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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return NULL;
		ListNode * tmp1=headA,*tmp2=headB;
		while(headA!=headB&&(headA||headB)) {//相等或同时为空结束
			headA=(!headA)?tmp2:headA->next;
			headB=(!headB)?tmp1:headB->next;
		}
		if(headA==headB) return headA;
		return NULL;
    }
};