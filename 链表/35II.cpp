/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//拼接拆分 O(n) O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        Node *tmp = head, *tmp2 = nullptr;
        while (tmp) { //拼接
            tmp2 = tmp->next;
            tmp->next = new Node(tmp->val);
            tmp->next->next = tmp2;
            tmp = tmp2;
        }
        Node *pre = head;
        tmp = head->next;
        while (tmp) { //random指针
            tmp->random = (pre->random == nullptr) ? pre->random :pre->random->next;
            if (tmp->next == nullptr)
                break;           
            pre = tmp->next;
            tmp = tmp->next->next;
        }
        pre = head;
        tmp = head->next;
        Node *ans = head->next; 
        while (tmp->next) {
            pre->next = tmp->next;
            tmp->next = tmp->next->next;
            pre = pre->next;
            tmp = tmp->next;
        }
        pre->next = nullptr;//原链表尾节点恢复
        return ans;
    }
};