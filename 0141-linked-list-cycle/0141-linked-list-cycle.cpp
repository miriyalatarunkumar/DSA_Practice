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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return 0;
        ListNode * slow =head;
        ListNode* fast=head;
        do{
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }while(fast && fast!=slow);
        if(fast && fast == slow) return 1;// when there is only 1 element, fast=slow=NULL, so, also check for fast!=NULL condition
        else return 0;
    }
};