class Solution {
    vector<int> ino;
public:
    void inorder(TreeNode *root){
        if(root==NULL) return;
        inorder(root->left);
        ino.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i=0, j=ino.size()-1;
        
        while(i<j){
            if(ino[i] + ino[j] == k) return true;
            else if(ino[i] + ino[j] < k) i+=1;
            else j-=1;
        }
        return false;
    }
};