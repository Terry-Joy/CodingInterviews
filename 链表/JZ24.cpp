/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		ListNode *pre=NULL;
		while(pHead){
			ListNode *tmp=pHead->next;
			pHead->next=pre;
			pre=pHead;
			pHead=tmp;
		}		
		return pre;
    }
};