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
        /*
        // My approach
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
        */
        
        //other approaches
        //https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/1654181/C%2B%2BPythonJava-Simple-Solution-w-Images-and-Explanation-or-BFS-%2B-DFS-%2B-O(1)-Optimized-BFS
        
        /*
        // (BFS - Right to Left) approach
        
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);        
        while(size(q)) {
            Node* rightNode = nullptr;         // set rightNode to null initially
            for(int i = size(q); i; i--) {     // traversing each level
                auto cur = q.front(); q.pop(); // pop a node from current level and,
                cur -> next = rightNode;    // set its next pointer to rightNode
                rightNode = cur;            // update rightNode as cur for next iteration
                if(cur -> right)            // if a child exists
                    q.push(cur -> right),   // IMP: push right first to do right-to-left BFS
                    q.push(cur -> left);    // then push left
            }
        }
        return root;
        
        //Time Complexity : O(N), where N is the number of nodes in the given tree. We only traverse the tree once using BFS which requires O(N).
        //Space Complexity : O(W) = O(N), where W is the width of given tree. This is required to store the nodes in queue. Since the given tree is a perfect binary tree, its width is given as W = (N+1)/2 ≈ O(N)
        
        */
        
        /*
        //Here we are taking the advantage of perfect binary tree (PBT)
        // and performing DFS
        // As it is PBT, if once child exists, the other exists as well.
        
        if(!root) return nullptr;
        auto L = root -> left, R = root -> right, N = root -> next;
        if(L) {
            L -> next = R;               // next of root's left is assigned as root's right
            if(N) R -> next = N -> left; // next of root's right is assigned as root's next's left (if root's next exist)
            connect(L);                  // recurse left  - simple DFS 
            connect(R);                  // recurse right
        }
        return root;
        
        //Time Complexity : O(N), each node is only traversed once
        //Space Complexity : O(logN), required for recursive stack. The maximum depth of recursion is equal to the height of tree which in this case of perfect binary tree is equal to O(logN)
        
        */
        
        // (BFS - Space-Optimized Appraoch)
        // Usually standard DFS/BFS takes O(N) space, but since we are given the next pointers in each node, we can use them to space-optimize our traversal to O(1).
        // This is a combination of logic of above logics- we will traverse in BFS manner but populate the next pointers of bottom level just as we did in the DFS solution.

        auto head = root;
        for(; root; root = root -> left){
            for(auto cur = root; cur; cur = cur -> next){ 
                // traverse each level - it's just BFS taking advantage of next pointers          
                if(cur -> left) {          // update next pointers of children if they exist 
                    cur -> left -> next = cur -> right;
                    if(cur -> next) cur -> right -> next = cur -> next -> left;
                }
                //else break;                // if no children exist, stop iteration
                // This break statement is optional
                // This condition is already covered in loop
            }
        }                                 
        return head;
        
        //Time Complexity : O(N), we only traverse each node once, basically doing a standard BFS.
        //Space Complexity : O(1), only constant extra space is being used
    }
};