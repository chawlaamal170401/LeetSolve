#define ll long long int
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>> > g(n);
        const int mod = 1e9+7;
        for(auto v: roads){
            g[v[0]].push_back({v[1], v[2]});
            g[v[1]].push_back({v[0], v[2]});
        }
        
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n, 0);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        
        pq.push({0, 0});
        ways[0] = 1;
        dist[0] = 0;
        
        while(!pq.empty()){
            ll d = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            
            if(d > dist[curr]) continue;
            
            for(auto ngh: g[curr]){
                ll cost = ngh.second;
                ll node = ngh.first;
                
                if(d + cost < dist[node]){
                    dist[node] = d + cost;
                    ways[node] = (ways[curr])%mod;
                    pq.push({d+cost, node});
                }        
                else if(d + cost == dist[node]) ways[node] = (ways[node] + ways[curr])%mod;

            }
        }
        return ways[n-1]%mod;
    }
};