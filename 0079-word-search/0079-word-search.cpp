class Solution {
public:
    bool dfs(vector<vector<char>> &mat, int i, int j, int n, int m, string w){
        if(w.size() == 0) return true;
        if(i<0 or i>=n or j<0 or j>=m or w[0] != mat[i][j]) return false;
        
        char ch = mat[i][j];
        mat[i][j] = '*';
        
        string search = w.substr(1);
            
        bool op1 = dfs(mat, i, j+1, n, m, search);
        bool op2 = dfs(mat, i+1, j, n, m, search);
        bool op3 = dfs(mat, i-1, j, n, m, search);
        bool op4 = dfs(mat, i, j-1, n, m, search);

        
        mat[i][j] = ch;
        return (op1 or op2 or op3 or op4);
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(board, i, j, n, m, word)) return true;
            }
        }
        return false;
    }
};