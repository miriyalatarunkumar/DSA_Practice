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
    int dfs(TreeNode* root, int &ans){
        if(!root)return 0;
        int left = max(0, dfs(root->left, ans));
        int right = max(0, dfs(root->right, ans));
        int curr = root->val  + left + right;
        ans = max(curr, ans);
        return root->val + max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        dfs(root, ans);
        return ans;
    }
};