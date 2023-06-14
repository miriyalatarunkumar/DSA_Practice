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
    TreeNode* build(vector<int> &preorder, int &i, int bound){ // Here bound is upperbound and i should only be passed by reference as it it a global pointer to the preorder array.
        if(i==preorder.size() || preorder[i] > bound) return NULL ;
        TreeNode* newnode = new TreeNode(preorder[i++]);
        newnode->left = build(preorder,i,newnode->val);
        newnode->right = build(preorder,i,bound);
        return newnode ; 
    }
    
    TreeNode* solve(vector<int> &preorder , long mini , long maxi , int &i){
        if(i>=preorder.size()) return NULL ;
        if(preorder[i] < mini || preorder[i] > maxi ) return NULL ;
        TreeNode* newnode = new TreeNode(preorder[i++]);
        newnode->left = solve(preorder,mini,newnode->val,i);
        newnode->right = solve(preorder,newnode->val,maxi,i);
        return newnode ; 
    }
    
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
        
        /*
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size()==1) return root;
        for(int i =1; i<preorder.size(); i++){
            insert(root, preorder[i]);
        }
        // At worstcase, insertion takes O(N) time (in case of skewed tree)
        // and we are inserting N elements => T.C.: O(N^2), S.C.: O(N)
        return root;
        */
        
        /*
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size()==1) return root;
        TreeNode *p = root;
        int i = 1;
        while(i<preorder.size()){
            if(preorder[i]<p->val){
                s.push(p);
                p->left = new TreeNode(preorder[i++]);
                p = p->left;
            }
            else{
                if(!s.empty()){
                    if(preorder[i]<s.top()->val){
                        p->right = new TreeNode(preorder[i++]);
                        p = p->right;
                    }
                    else{
                        p = s.top();
                        s.pop();
                    }
                }
                else{
                    p->right = new TreeNode(preorder[i++]);
                    p = p->right;
                }
            }
        }
        return root;
        */
        
        /*
        int i=0;
        long mini = LONG_MIN; // if -ve no.s there, use -LONG_MAX;
        long maxi  = LONG_MAX; // can also use int instead of long
        return solve(preorder,mini,maxi,i);
        */
        int i = 0;
        return build(preorder,i,INT_MAX);
    }
};