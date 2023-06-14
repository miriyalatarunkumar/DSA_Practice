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
    void insert(TreeNode* &root, int num){
        TreeNode *q, *p=root;
        while(p){
            if(num<p->val){
                q = p;
                p = p->left;
            }
            else if(num>p->val){
                q = p;
                p = p->right;
            }
        }
        if(num<q->val)q->left = new TreeNode(num);
        else q->right = new TreeNode(num);
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size()==1) return root;
        for(int i =1; i<preorder.size(); i++){
            insert(root, preorder[i]);
        }
        return root;
    }
};