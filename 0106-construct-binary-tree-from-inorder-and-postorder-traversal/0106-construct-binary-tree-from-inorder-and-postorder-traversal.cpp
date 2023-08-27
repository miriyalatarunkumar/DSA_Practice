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
    TreeNode* build(vector<int>& postorder, int poststart, int postend, vector<int>& inorder, int instart, int inend, unordered_map<int,int> &m){
        if(poststart>postend || instart>inend) return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = m[postorder[postend]];
        int n = inroot-instart;
        root->left = build(postorder, poststart, poststart+n-1, inorder, instart, inroot-1, m);
        root->right = build(postorder, poststart+n, postend-1, inorder, inroot+1, inend, m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        int n = postorder.size();
        for(int i=0; i<n; i++){
            m[inorder[i]]=i;
        }
        TreeNode * root = build(postorder, 0, n-1, inorder, 0, n-1, m);
        return root;
    }
};