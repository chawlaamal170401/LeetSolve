class Solution {
public:
    vector<int> solve(vector<vector<int>> &g, int node, int n){
        vector<int> dis(n, 1e9);
        
        queue<int> q;
        q.push(node);
        dis[node] = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int ngh: g[curr]){
                if(dis[curr] + 1 < dis[ngh]){
                    dis[ngh] = 1 + dis[curr];
                    q.push(ngh);
                }
            }
        }
        return dis;
    }
    
    int closestMeetingNode(vector<int>& e, int node1, int node2) {
        int n = e.size();
        vector<vector<int>> g(n, vector<int>());
        
        for(int i=0; i<n; i++){
            if(e[i] != -1)
                g[i].push_back(e[i]);
        }
        
        vector<int> d1 = solve(g, node1, n);
        vector<int> d2 = solve(g, node2, n);
        
        int maxi = INT_MAX, ans = -1;
        
        for(int i=0; i<n; i++){
            if(d1[i] == 1e9 or d2[i] == 1e9) continue;
            if(maxi > max(d1[i], d2[i])){
                ans = i;
                maxi = max(d1[i], d2[i]);
            }
        }
        return ans;
    }
};