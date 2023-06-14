/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int minDifference = INT_MAX;
    // Initially, it will be null.
    TreeNode* prevNode;  
    void inorderTraversal(TreeNode* node) {
        if (node == NULL) return;
        
        inorderTraversal(node->left);
        // Find the difference with the previous value if it is there.
        if (prevNode != NULL) {
            minDifference = min(minDifference, node->val - prevNode->val);
        }
        prevNode = node;
        inorderTraversal(node->right);
    }
    
    /*
    void inorder(TreeNode* node, vector<int> &v){
        if (node == NULL) return;
        inorder(node->left,v);
        v.push_back(node->val);
        inorder(node->right,v);
    }
    */
    
    /*
    TreeNode* ip(TreeNode* root){
        TreeNode *p=root;
        if(p->left){
            p = p->left;
            while(p->right){
                p = p->right;
            }
        }
        return p;
    }
    TreeNode* is(TreeNode* root){
        TreeNode *s=root;
        if(s->right){
            s = s->right;
            while(s->left){
                s = s->left;
            }
        }
        return s;
    }
    */
    
public:
    int minDiffInBST(TreeNode* root) {
        
        /*
        int diff = INT_MAX, rd = INT_MAX, ld = INT_MAX;
        int pd = abs(root->val - ip(root)->val);
        if(pd>0) diff = min(diff,pd);
        int sd = abs(root->val - is(root)->val);
        if(sd>0) diff = min(diff,sd);
        if(diff == 1) return diff;
        if(root->right) rd = getMinimumDifference(root->right);
        if(rd == 1) return rd;
        if(root->left) ld = getMinimumDifference(root->left);
        if(ld == 1) return ld;
        diff = min(diff,rd);
        diff = min(diff, ld);
        return diff;
        */
        /*
        vector<int> v;
        inorder(root, v);
        int diff = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            diff = min(diff, v[i] - v[i-1]);
        }
        return diff;
        */
        
        inorderTraversal(root);
        return minDifference;
        
    }
};