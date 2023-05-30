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
    void preoT(TreeNode* root, vector<int> &v){
        if(root == NULL) return ;
        v.push_back(root->val);
        preoT(root->left,v);
        preoT(root->right,v);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preoT(root,v);
        return v;
    }
};