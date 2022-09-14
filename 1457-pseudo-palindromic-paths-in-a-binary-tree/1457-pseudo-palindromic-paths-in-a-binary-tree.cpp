class Solution {
    int ans = 0;
public:
    void solve(TreeNode *root, int cnt){
        if(root == NULL) return;
        cnt ^= (1<<root->val);
        if(root->left == NULL and root->right == NULL){
            int v = (cnt) & (cnt-1);
            if(v == 0){
                ans += 1;
            }
        }
        solve(root->left, cnt);
        solve(root->right, cnt);
    
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};