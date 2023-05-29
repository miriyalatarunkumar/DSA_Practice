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
        ListNode* Newhead;
        ListNode* tail;
        if(list1&&list2){
            if(list1->val<list2->val){
                Newhead=list1;
                tail = Newhead;
                list1=list1->next;
                tail->next = list2;
            }
            else{
                Newhead=list2;
                tail = Newhead;
                list2=list2->next;
                tail->next = list2;
            }
        }
        else{
            if(list1) return list1;
            else return list2;
        }
        while(list1 &&list2){
            if(list1->val < list2->val){
                tail->next = list1;
                tail=tail->next;
                list1= list1->next;
            }
            else{
                tail->next = list2;
                tail=tail->next;
                list2 = list2->next;
            }
        }
        if(list2==NULL) tail->next = list1;
        if(list1 == NULL) tail->next = list2;
        return Newhead;
    }
};