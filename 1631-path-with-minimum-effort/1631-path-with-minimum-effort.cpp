typedef pair<int, pair<int, int>> pii;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        vector<int> row = {-1, 0, 0, 1};
        vector<int> col = {0, -1, 1, 0};
        
        
        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if(r == n-1 and c == m-1) return d;
            
            for(int i=0; i<4; i++){
                int x = r + row[i];
                int y = c + col[i];
                
                if(x<0 or x>=n or y<0 or y>=m) continue;
                int effort = max(abs(heights[r][c] - heights[x][y]), d);
                if(effort < dist[x][y]){
                    dist[x][y] = effort;
                    pq.push({effort, {x, y}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};