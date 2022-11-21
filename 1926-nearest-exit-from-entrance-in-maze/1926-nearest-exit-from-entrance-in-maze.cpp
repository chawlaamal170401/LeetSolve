class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size(), level = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto curr = q.front();
                q.pop();
                int x = curr.first, y = curr.second;

                
                for(int k=0; k<4; k++){
                    int tx = x + dx[k], ty = y + dy[k];
                    if(tx < 0 or ty < 0 or tx >= n or ty >= m or maze[tx][ty] == '+' or visited[tx][ty]) continue;
                    if(tx == n-1 or ty == 0 or ty == m-1 or tx == 0) return level + 1;
                    visited[tx][ty] = true;
                    q.push({tx, ty});
                }
            }
            level += 1;
        }
        return -1;
    }
};