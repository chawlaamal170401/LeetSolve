class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q; 
        q.push(root); 
        int level=0; 
        
        while (!q.empty()) {
            vector<int> nums; 
            int n = q.size();
            vector<TreeNode*> nodes; 
            
            
            for (int i=0; i < n; i++){
                TreeNode* curr= q.front(); 
                q.pop();
                nums.push_back(curr->val); 
                nodes.push_back(curr); 
                if(curr->left) q.push(curr->left); 
                if(curr->right) q.push(curr->right); 
                
            }
            
            if(level & 1){
                reverse(nums.begin(), nums.end()); 
                for (int i=0; i<nodes.size(); i++) {
                    TreeNode* curr = nodes[i]; 
                    curr->val = nums[i]; 
                }
            }
            level++;
            
        }
        
        return root;
    }
};