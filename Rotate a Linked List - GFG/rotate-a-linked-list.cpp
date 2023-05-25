//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
Node * rev(Node*c,Node*end){
    Node*a=NULL,*b=NULL;
    while(c!=end){
        a=b;
        b=c;
        c=c->next;
        b->next=a;
    }
    return b;
}


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(head==NULL||head->next==NULL||k==0) return head;
        // Your code here
        Node*p=head,*r=head,*q=NULL;
        int cnt =0;
        while(p){
            cnt++;
            p=p->next;
        }
        p=head;
        if(k>cnt)k=k%cnt;
        while(k-1){
            p=p->next;
            k--;
        }
        q=p->next;
        // Reverse the first part start from head to before q(p)
        //r(head)->p becomes head1->r
        Node*head1=rev(head,q);
        // Reverse the second part start from q to before NULL
        //q->last element becomes head2->q
        Node*head2=rev(q,NULL);
        //connect 2 parts
        r->next=head2;
        // reverse again => head1->q becomes head(q)->head1
        head = rev(head1,NULL);
        return head;
        
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends