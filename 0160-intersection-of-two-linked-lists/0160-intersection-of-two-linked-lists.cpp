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
        
    }
};