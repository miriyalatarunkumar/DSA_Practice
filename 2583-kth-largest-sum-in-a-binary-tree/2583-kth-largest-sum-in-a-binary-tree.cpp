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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector <long long> ans;
        queue <TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while(!q.empty()){
            long long sum = 0;
            queue <TreeNode*> q2;
            TreeNode* node;
            while(!q.empty()){
                node=q.front();
                q.pop();
                sum += node->val;
                if(node->left) q2.push(node->left);
                if(node->right) q2.push(node->right);
            }
            ans.push_back(sum);
            q=q2;
        }
        if (ans.size()<k)return -1;
        sort(ans.begin(),ans.end(),greater<long long>());
        return ans[k-1];
    }
};