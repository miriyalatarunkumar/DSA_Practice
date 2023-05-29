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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        /*
        ListNode * ans = new ListNode();
        ListNode* tail=ans;
        int num = l1->val+l2->val;
        l1=l1->next;
        l2=l2->next;
        ans->val = num%10;
        num = num/10;
        while(l1 && l2){
            ListNode * newNode = new ListNode();
            num += l1->val+l2->val;
            l1=l1->next;
            l2=l2->next;
            newNode->val = num%10;
            tail->next = newNode;
            tail=tail->next;
            num = num/10;
        }
        while(l1){
            ListNode * newNode = new ListNode();
            num += l1->val;
            l1=l1->next;
            newNode->val = num%10;
            tail->next = newNode;
            tail=tail->next;
            num = num/10;
        }
        while(l2){
            ListNode * newNode = new ListNode();
            num += l2->val;
            l2=l2->next;
            newNode->val = num%10;
            tail->next = newNode;
            tail=tail->next;
            num = num/10;
        }
        while(num){
            ListNode * newNode = new ListNode();
            newNode->val = num%10;
            tail->next = newNode;
            tail=tail->next;
            num = num/10;
        }
        return ans;
        
        */
        
        ListNode * ans = new ListNode();
        ListNode* tail=ans;
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            tail -> next = node; 
            tail = tail -> next; 
        }
        return ans -> next; 
        
    }
};