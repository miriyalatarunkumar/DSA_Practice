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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto c = root, p = root;
        auto t = new TreeNode(val);
        if(!root)return t;
        while(c){
            p=c;
            if(c->val<val)c=c->right;
            else c=c->left;
        }
        if(p->val<val)p->right=t;
        else p->left=t;
        return root;
    }
};