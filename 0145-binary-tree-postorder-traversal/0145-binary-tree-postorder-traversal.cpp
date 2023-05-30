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
    void posoT(TreeNode* root, vector<int> &v){
        if(root == NULL) return ;
        posoT(root->left,v);
        posoT(root->right,v);
        v.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        /*
        
        vector<int> v;
        posoT(root,v);
        return v;
        
        */
        
        vector<int> ans;
        if (root == NULL) return ans;
        vector<int> left = postorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        vector<int> right = postorderTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());
        ans.push_back(root->val);
        return ans;
    }
};