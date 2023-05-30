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
private:
    void rev(ListNode*p, ListNode* &newhead, ListNode* &newtail,ListNode * &h, int k){
        ListNode * r = NULL;
        ListNode * q = NULL;
        newtail = p;
        ListNode* a = p;
        int n =0;
        while(n<=k && a){
            a=a->next;
            n++;
        }
        if (n<k){
            newhead = NULL;
            h= p;
            return;
        }
        
        while(k && p){
            r=q;
            q = p;
            p=p->next;
            q->next = r;
            k--;
        }
        newhead = p;
        h = q;
        
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * tail = head;
        ListNode * head1;
        ListNode* tail1;
        ListNode* h;
        ListNode* newhead;
        
        rev(head,head1,tail1,h,k);
        newhead=h;
        head = head1;
        
        while(head!=NULL){
            rev(head,head1,tail1,h,k);
            tail-> next = h;
            tail = tail1;
            head =head1;   
        }
        return newhead;
    }
};