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
    ListNode *detectCycle(ListNode *head) {
        // can be done by hashing using unordered_set.
        if(!head) return head;
        unordered_set<ListNode*> s;
        while(head){
            if(s.count(head))return head;
            s.insert(head);
            head=head->next;
        }
        return head;
    }
};