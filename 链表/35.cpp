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
//哈希表 O(n) O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        unordered_map<Node*, Node*> mp;
        Node *head2 = nullptr, *head1 = head;
        Node *tmp = head2;
        while (head) {
            tmp = new Node(head->val);
            mp[head] = tmp;
            head = head->next;
            tmp = tmp->next;
        }
        while (head1) {
            head2->random = mp[head1->random];
            head2 = head2->next;
            head1 = head1->next;
        }
        return tmp;
    }
};