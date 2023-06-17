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
    TreeNode* kthsmallest(TreeNode* root,int &k)
    {
        if(root==NULL)
        return NULL;

        TreeNode* left=kthsmallest(root->left,k);
        if(left!=NULL)
        return left;
        k--;
        if(k==0)
        return root;

        return kthsmallest(root->right,k);
    }
    
    void inorder(TreeNode* root, int &ans, int &k,int &flag){
        if(flag)return;
        if(!root)return;
        inorder(root->left,ans,k,flag);
        k--;
        if(!k){
            ans=root->val;
            flag=1;
            return;
        }
        inorder(root->right,ans,k,flag);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        /*
        int ans = 0,flag=0;
        inorder(root,ans,k,flag);
        return ans;
        */
        return kthsmallest(root,k)->val;
    }
};