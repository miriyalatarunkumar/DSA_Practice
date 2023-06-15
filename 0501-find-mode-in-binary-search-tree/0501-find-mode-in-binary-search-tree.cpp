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
    void dfs1(TreeNode* root, unordered_map<int,int> &m){
        if(!root) return;
        m[root->val]++;
        dfs1(root->left, m);
        dfs1(root->right, m);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        dfs1(root, m);
        vector<int> ans;
        int frequency = 0;
        for(auto it : m){
            if(it.second == frequency) ans.push_back(it.first);
            if(it.second > frequency){
                ans.clear();
                ans.push_back(it.first);
                frequency = it.second;
            }
        }
        return ans;
    }
};