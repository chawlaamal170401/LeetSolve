class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int ans = 0, n = plantTime.size();
        vector<pair<int, int>> v;
        
        for(int i=0; i<n; i++) 
            v.push_back({growTime[i], plantTime[i]});
        
        sort(v.begin(), v.end());
        
        for(auto p: v) 
            ans = max(ans, p.first) + p.second;
        
        return ans;
    }
};