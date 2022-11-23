class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]!='.'){
                    if(!valid(board, i, j, n, m)) return false;
                }
            }
        }
        return true;
    }
    
    bool valid(vector<vector<char>>& board, int i, int j, int n, int m){
        char value = board[i][j];
        for(int x=0; x<n; x++){
            if(x!=i and board[x][j]==value) return false;
        }
        
        for(int y=0; y<m; y++){
            if(y!=j and board[i][y]==value) return false;
        }
        
        int row = (i/3)*3;
        int col = (j/3)*3;
        
        for(int x=row; x<row+3; x++){
            for(int y=col; y<col+3; y++)
                if(x!=i and y!=j and board[x][y]==value) return false;
        }
        
        return true;
    }
    
};