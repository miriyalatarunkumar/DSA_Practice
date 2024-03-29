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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* Newhead;
        ListNode* tail;
        if(list1->val<list2->val){
            Newhead=tail=list1;
            list1=list1->next;
            tail->next=nullptr;
        }
        else{
            Newhead=tail=list2;
            list2=list2->next;
            tail->next=NULL;
        }
        while(list1 &&list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1= list1->next;
                tail= tail->next;
                tail->next =NULL;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
                tail=tail->next;
                tail->next=NULL;
            }
        }
        if(list2==NULL) tail->next = list1;
        if(list1 == NULL) tail->next = list2;
        return Newhead;
    }
};