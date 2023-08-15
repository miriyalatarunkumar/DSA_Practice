/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
        ListNode* p = head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* tail = dummy;
        while(p && p->val < x){
            tail = p;
            p=p->next;
        }
        if(!p) return head;
        ListNode* q = p;
        ListNode* r = p->next;
        while(r){
            if(r->val<x){
                q->next=r->next;
                r->next=p;
                tail->next=r;
                tail=r;
                r=q->next;
            }
            else{
                q=r;
                r=r->next;
            }
        }
        if(head->val>=x)head = dummy->next;
        return head;
    }
};