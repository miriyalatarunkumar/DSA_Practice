class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL; // Added check for empty list

        Node* p = head;
        while (p) {
            Node* n = new Node(p->val);
            n->next = p->next;
            p->next = n;
            p = n->next;
        }
        Node* newhead = head->next;
        p = head;
        while (p) {
            p->next->random = p->random ? p->random->next : NULL;
            p=p->next->next;
        }
        p=head;
        while(p){
            Node* q = p->next;
            p->next=q->next;
            p=p->next;
            if(p && q)q->next=p->next;
        }
        return newhead;
    }
};
