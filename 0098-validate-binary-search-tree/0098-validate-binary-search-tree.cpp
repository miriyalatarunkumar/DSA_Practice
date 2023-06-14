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
    bool fun(TreeNode* root, long min, long max){
        if(!root) return true;
        bool l = true, r = true;
        if(root->val >= max || root->val <= min) return false;
        l = fun(root->left, min, root->val);
        r = fun(root->right, root->val, max);
        return l&&r;
    }
    
    bool inorder(TreeNode* root, TreeNode* &prev){
        if(!root) return true;
        bool l = true, r = true;
        l = inorder(root->left, prev);
        if(prev){
            if(prev->val >= root->val) return false;
        }
        prev = root;
        r = inorder(root->right, prev);
        return (l&&r)?true:false;
    }
public:
    bool isValidBST(TreeNode* root) {
        /*
        TreeNode* prev = NULL;
        return inorder(root, prev);
        */
        
        return fun(root, LONG_MIN, LONG_MAX);
    }
};