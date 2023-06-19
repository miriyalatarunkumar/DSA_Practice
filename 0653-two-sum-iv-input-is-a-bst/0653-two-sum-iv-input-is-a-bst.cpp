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
    
    void inorder(TreeNode* root, vector<int> &v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    void solve(TreeNode* root, int k, unordered_set<int> &s, bool &ans){
        if(ans)return;
        if(!root) return;
        solve(root->left, k, s, ans);
        if(s.count(k-root->val)){
            ans = true;
            return;
        } 
        else s.insert(root->val);
        solve(root->right, k, s, ans);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        /*
        // T.C.: O(n)+O(n) => O(n)
        // S.C.: O(n) for vector
        vector<int> v;
        inorder(root, v);
        int i = 0;
        int j = v.size()-1;
        while(i<j){
            if(v[i]+v[j]==k) return true;
            else if(v[i]+v[j]>k)j--;
            else i++;
        }
        return false;
        */
        
        // T.C.: O(n)
        // S.C.: O(n) in worst case
        unordered_set<int> s;
        bool ans = false;
        solve(root, k, s, ans);
        return ans;
        
    }
};