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
    vector<TreeNode*> generate(int left, int right){
        if(left>right) return {NULL};
        vector<TreeNode*> ans;
        for(int i=left; i<=right; i++){
            auto lsubtrees = generate(left, i-1);
            auto rsubtrees = generate(i+1, right);
            for(auto l : lsubtrees){
                for(auto r : rsubtrees){
                    TreeNode* t = new TreeNode(i, l, r);
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};