/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || (root->right == NULL && root -> left == NULL)) return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            queue<Node*> q1;
            Node* p;
            while(!q.empty()){
                p = q.front();
                q.pop();
                if(p->left)q1.push(p->left);
                if(p->right)q1.push(p->right);
                if(!q.empty())p->next = q.front();
            }
            q=q1;
        }
        return root;
    }
};