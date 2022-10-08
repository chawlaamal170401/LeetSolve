class Solution {
public:
    void dfs(int src, vector<vector<int>> &g, vector<bool> &vis, unordered_set<int> &s, int &ans){
        vis[src] = true;
        ans += 1;
        
        for(int ngh: g[src]){
            if(!vis[ngh] and !s.count(ngh))
                dfs(ngh, g, vis, s, ans);
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& e, vector<int>& r) {
        vector<vector<int>> g(n, vector<int>());
        unordered_set<int> s(r.begin(), r.end());
        
        for(int i=0; i<n-1; i++){
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
        }
        
        vector<bool> vis(n, false);
        
        int ans = 0;
        dfs(0, g, vis, s, ans);
        return ans;
    }
};