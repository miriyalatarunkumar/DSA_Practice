/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:

    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        while(root){
            if(root->val > p->val && root->val > q->val) root = root->left;
            else if(root->val < p->val && root->val < q->val) root = root->right;
            else break;
        }
        return root;
        
        /*
        if(root==NULL) return NULL;
        if(root->val>p->val&&root->val>q->val)return lowestCommonAncestor(root->left, p,q);
        if(root->val<p->val&&root->val<q->val)return lowestCommonAncestor(root->right, p,q);
        return root;
        */
    }
};