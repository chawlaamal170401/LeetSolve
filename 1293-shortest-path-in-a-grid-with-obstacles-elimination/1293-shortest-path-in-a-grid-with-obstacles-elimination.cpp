#define pi pair<int, pair<int, pair<int, int>>>
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        priority_queue<pi, vector<pi>, greater<pi>> q;
        q.push({0, {0, {0, 0}}});
        
        dist[0][0] = 0;
        vector<int> row = {-1, 0, 0, 1};
        vector<int> col = {0, -1, 1, 0};
        
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int steps = it.first;
            int d = it.second.first;
            int r = it.second.second.first;
            int c = it.second.second.second;
            
            if(steps > k) continue;
            
            for(int i=0; i<4; i++){
                int x = row[i] + r;
                int y = col[i] + c;
                
                if(x<0 or x>=n or y<0 or y>=m) continue;
                if(grid[x][y] == 1 and steps > k) continue;
                
                if(d + 1 < dist[x][y]){
                    dist[x][y] = d+1;
                    if(grid[x][y] == 1 and steps <= k){
                        q.push({steps + 1, {d + 1, {x, y}}});
                    }
                    else{
                        q.push({steps, {d + 1, {x, y}}});
                    }
                }
                
            }
        }
        return dist[n-1][m-1] == 1e9 ? -1 : dist[n-1][m-1];
    }
};