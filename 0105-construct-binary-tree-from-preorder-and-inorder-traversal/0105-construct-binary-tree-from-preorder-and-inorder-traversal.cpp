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
    TreeNode* build(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, unordered_map<int,int> &m){
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = m[preorder[prestart]];
        int n = inroot-instart;
        root->left = build(preorder, prestart+1, prestart+n, inorder, instart, inroot-1, m);
        root->right = build(preorder, prestart+n+1, preend, inorder, inroot+1, inend, m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        int n = preorder.size();
        for(int i=0; i<n; i++){
            m[inorder[i]]=i;
        }
        TreeNode * root = build(preorder, 0, n-1, inorder, 0, n-1, m);
        return root;
    }
};