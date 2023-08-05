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
    vector<TreeNode*> generate(int left, int right, map<pair<int, int>, vector<TreeNode*>>& dp){
        vector<TreeNode*> ans;
        if(left>right){
            ans.push_back(NULL);
            return ans;
        }
        if(dp.count({left,right})) return dp[{left,right}];
        for(int i=left; i<=right; i++){
            auto lsubtrees = generate(left, i-1, dp);
            auto rsubtrees = generate(i+1, right, dp);
            for(auto l : lsubtrees){
                for(auto r : rsubtrees){
                    TreeNode* root = new TreeNode(i, l, r);
                    ans.push_back(root);
                }
            }
        }
        return dp[{left,right}] = ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
         map<pair<int, int>, vector<TreeNode*>> dp;
        return generate(1, n, dp);
    }
};