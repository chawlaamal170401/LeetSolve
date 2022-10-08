class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool chk(vector<vector<int>>& temp){
        for(int i=0; i<temp.size(); i++){
            for(int j=0; j<temp[0].size(); j++){
                if(temp[i][j]==1) return false;
            }
        }
        return true;
    }
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size(), move = 0;
        
        set<vector<vector<int>>> vis;
        queue<vector<vector<int>>> q;
        vector<vector<int>> t1;
        
        vis.insert(mat);
        q.push(mat);
        
        
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                if(chk(q.front())) return move;
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        t1 = q.front();
                        t1[i][j] = 1 - t1[i][j];
                        
                        for(int d=0; d<4; d++){
                            int ni = i + dx[d];
                            int nj = j + dy[d];
                            if(ni>=0 and nj>=0 and ni<n and nj<m){
                                t1[ni][nj] = 1 - t1[ni][nj];
                            }
                        }
                        if(!vis.count(t1)){
                            q.push(t1);
                            vis.insert(t1);
                        }
                    }
                }
                q.pop();
            }
            move++;
        }
        return -1;
    }
};