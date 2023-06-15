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
    void dfs(TreeNode* node, int level, vector<int>& sumOfNodesAtLevel) {
        if (node == nullptr) {
            return;
        }

        if (sumOfNodesAtLevel.size() == level) {
            sumOfNodesAtLevel.push_back(node->val);
        } else {
            sumOfNodesAtLevel[level] += node->val;
        }

        dfs(node->left, level + 1, sumOfNodesAtLevel);
        dfs(node->right, level + 1, sumOfNodesAtLevel);
    }
    
public:
    int maxLevelSum(TreeNode* root) {
        /*
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
        */
        
        /*
        queue<TreeNode*> q;
        int ans = 1,level =1;
        int sum = root->val;
        q.push(root);        
        while(size(q)) {
            int sum1 = 0; 
            for(int i = size(q); i; i--) {      // traversing each level 
                auto p = q.front(); q.pop();    // pop a node from current level
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
                sum1+=p->val;  
            }
            if(sum1>sum){
                ans = level;
                sum = sum1;
            }
            level++;
        }
        return ans;
        */
        
        /*
        // same as above only but slight syntax different
        int maxSum = INT_MIN;
        int ans = 0, level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            level++;
            int sumAtCurrentLevel = 0;
            // Iterate over all the nodes in the current level.
            for (int sz = q.size(); sz > 0; --sz) {
                TreeNode* node = q.front();
                q.pop();
                sumAtCurrentLevel += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (maxSum < sumAtCurrentLevel) {
                maxSum = sumAtCurrentLevel;
                ans = level;
            }
        }

        return ans;
        */
        
        //DFS
        vector<int> sumOfNodesAtLevel;
        dfs(root, 0, sumOfNodesAtLevel);

        int maxSum = INT_MIN;
        int ans = 0;

        for (int i = 0; i < sumOfNodesAtLevel.size(); i++) {
            if (maxSum < sumOfNodesAtLevel[i]) {
                maxSum = sumOfNodesAtLevel[i];
                ans = i + 1;
            }
        }

        return ans;
    }
};