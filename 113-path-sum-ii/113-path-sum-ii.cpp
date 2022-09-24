class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }
    
    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == NULL) return;
        path.push_back(root->val);
        targetSum -= root->val;
        if (root->left == NULL and root->right == NULL) { 
            if (targetSum == 0) 
                ans.push_back(path);
        } 
        else {
            dfs(root->left, targetSum, path);
            dfs(root->right, targetSum, path);
        }
        path.pop_back(); 
    }
};