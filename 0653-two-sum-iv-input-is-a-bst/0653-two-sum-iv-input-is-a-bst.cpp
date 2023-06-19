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
    void solve(TreeNode* root, int k, unordered_set<int> &s, bool &ans){
        if(ans)return;
        if(!root) return;
        solve(root->left, k, s, ans);
        if(s.count(k-root->val)){
            ans = true;
            return;
        } 
        else s.insert(root->val);
        solve(root->right, k, s, ans);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        bool ans = false;
        solve(root, k, s, ans);
        return ans;
    }
};