class Solution {
    int ans = 0;
public:
    void dfs(TreeNode *root, bool flag, int steps){
        if(root == NULL) return;
        ans = max(ans, steps);
        
        if(flag){
            dfs(root->left, false, steps + 1);
            dfs(root->right, true, 1);
        }
        else{
            dfs(root->right, true, steps + 1);
            dfs(root->left, false, 1);
        }
        
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        
        return ans;
    }
};