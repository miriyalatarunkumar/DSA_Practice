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
        /*    
            ListNode* p=head;
            ListNode* q=head;
            int N=0;
            while(p){
                N++;
                p=p->next;
            }
            int delNodePrev = N-n;
        // If n ==N, i.e, to delete the 1st element
            if(N-n == 0) return head->next;
            for(int i = 0; i< delNodePrev-1; i++){
                q=q->next;
            }
            p = q->next;
            q->next = p-> next;
            return head;
        */
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* slow = start;
        ListNode* fast = start;
        for(int i = 0;i<n;i++){
            fast = fast->next;
        }
        while(fast->next !=NULL){ // i.e, fast is not the last element
            slow = slow->next;
            fast = fast->next;
        }
        // if n=N, then slow won't move and will be at start only
        slow->next = slow->next->next;
        
        return start->next;
        // i.e, head in normal case and head->next in case of n=N because slow->next points to head->next, i.e, start-> next points to head->next which is new head.
    }
};