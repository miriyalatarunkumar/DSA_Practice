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
    void inorder(TreeNode* node, TreeNode* &newroot, TreeNode* &tail){
        if(node == NULL) return;
        inorder(node->left, newroot, tail);
        if(newroot == NULL){
            TreeNode* p = new TreeNode(node->val);
            newroot = p;
            tail = p;
        }
        else {
            TreeNode* p = new TreeNode(node->val);
            tail->right = p;
            tail = tail->right;
        }
        inorder(node->right, newroot, tail);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newroot = NULL, *tail = NULL;
        inorder(root, newroot, tail);
        return newroot;
    }
};