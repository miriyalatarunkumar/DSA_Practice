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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int ans = 1,level =1;
        int sum = root->val;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*>q1;
            int sum1 = 0;
            while(!q.empty()){
                TreeNode* p = q.front();
                q.pop();
                if(p->left)q1.push(p->left);
                if(p->right)q1.push(p->right);
                sum1+=p->val;
            }
            if(sum1>sum){
                ans = level;
                sum = sum1;
            }
            level++;
            q=q1;
        }
        return ans;
    }
};