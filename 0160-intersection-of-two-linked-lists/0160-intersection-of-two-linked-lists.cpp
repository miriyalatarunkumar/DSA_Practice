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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        /*
        vector <ListNode *> s1,s2;
        ListNode* ans=NULL;
        while(headA){
            s1.push_back(headA);
            headA=headA->next;
        }
        while(headB){
            s2.push_back(headB);
            headB=headB->next;
        }
        while(!s1.empty() && !s2.empty() && s1.back()==s2.back()){
            ans= s1.back();
            s1.pop_back();
            s2.pop_back();
        }
        return ans;
        
        */
        
        /*
        
        stack <ListNode *> s1,s2;
        ListNode* ans=NULL;
        while(headA){
            s1.push(headA);
            headA=headA->next;
        }
        while(headB){
            s2.push(headB);
            headB=headB->next;
        }
        while(!s1.empty() && !s2.empty() && s1.top()==s2.top()){
            ans= s1.top();
            s1.pop();
            s2.pop();
        }
        return ans;
        
        */

        
        int s1 =0;
        int s2 = 0;
        ListNode * l1 = headA;
        ListNode * l2 = headB;
        while (l1){
            s1++;
            l1=l1->next;
        }
        while (l2){
            s2++;
            l2=l2->next;
        }
        l1 = headA;
        l2 = headB;
        int diff = abs(s1-s2);
        if(s1<s2){
            while(diff) {
                l2=l2->next;
                diff--;
            }
        }
        else{
            while(diff){
                l1=l1->next;
                diff--;
            } 
        }
        // Now they are at same level
        while(l1 && l2 && l1!=l2){
            l1=l1->next;
            l2=l2->next;
        }
        return l1; // or l2 as they are equal
        
        
        
        
    }
};