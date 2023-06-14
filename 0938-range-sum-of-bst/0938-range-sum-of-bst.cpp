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
    void dfs(TreeNode* node, int &low, int &high, int &ans){
        if (node != NULL) {
            if (low <= node->val && node->val <= high)
                ans += node->val;
            if (low < node->val)
                dfs(node->left, low, high, ans);
            if (node->val < high)
                dfs(node->right, low, high, ans);
        }
    }
    void inorder(TreeNode* node, int &low, int &high, int &ans){
        if(node==NULL) return;
        inorder(node->left,low,high,ans);
        if(node->val >= low && node->val <= high) ans+=node->val;
        if(node->val >= high) return;
        inorder(node->right,low,high,ans);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        //inorder(root, low, high, ans);
        //dfs(root,low,high,ans);
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            if (node != NULL) {
                if (low <= node->val && node->val <= high)
                    ans += node->val;
                if (low < node->val)
                    s.push(node->left);
                if (node->val < high)
                    s.push(node->right);
            }
        }
        return ans;
        
    }
};