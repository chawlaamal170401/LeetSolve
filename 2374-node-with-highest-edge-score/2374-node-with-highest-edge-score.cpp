#define ll long long int
class Solution {
public:
    int edgeScore(vector<int>& e) {
        int n = e.size();
        vector<vector<int>> g(n, vector<int>());
        
        for(int i=0; i<n; i++){
            g[i].push_back(e[i]);
        }
        
        ll maxi = 0;
        ll ans = 0;
        vector<ll> indegree(n, 0);
        
        for(int i=0; i<n; i++){
            for(int ngh: g[i]){
                indegree[ngh] += i;
            }
        }
        
        maxi = indegree[0];
        for(int i=1; i<n; i++){
            if(maxi < indegree[i]){
                ans = i;
                maxi = indegree[i];
            }    
        }
        return ans;
    }
};