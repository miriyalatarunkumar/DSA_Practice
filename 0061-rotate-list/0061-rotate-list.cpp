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
ListNode* rev(ListNode* c,ListNode*end){
    ListNode*a=NULL,*b=NULL;
    while(c!=end){
        a=b;
        b=c;
        c=c->next;
        b->next = a;
    }
    return b;
}
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0) return head;
        ListNode*p =head,*r=head,*q=NULL;
        int cnt =0,n;
        while(p){
            cnt++;
            p=p->next;
        }
        p=head;
        k=k%cnt;
        n=cnt-k;
        while(n-1){
            p=p->next;
            n--;
        }
        q=p->next;
        ListNode* head1=rev(head,q);
        ListNode* head2=rev(q,NULL);
        r->next = head2;
        head = rev(head1,NULL);
        return head;
    }
};