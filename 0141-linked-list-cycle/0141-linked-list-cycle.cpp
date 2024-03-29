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
        
        /*
        
        unordered_set<ListNode*> hashTable;
        while(head != NULL) {
            if(hashTable.find(head) != hashTable.end()) return true;
            hashTable.insert(head);
            head = head->next;
        }
        return false;
        
        */
        
        /*
        
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
        
        */
        
        /*
        
        if(head == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
        
        */
        
        if(head == NULL || head -> next == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;        
    }
};