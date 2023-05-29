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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* p=head;
            ListNode* q=head;
            int N=0;
            while(p){
                N++;
                p=p->next;
            }
            int delNodePrev = N-n;
            if(N-n == 0) return head->next;
            for(int i = 0; i< delNodePrev-1; i++){
                q=q->next;
            }
            p = q->next;
            q->next = p-> next;
            return head;
    }
};