class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> s;
        
        for(int x: arr) mp[x] += 1;
        
        for(auto p: mp){
            if(s.count(p.second)) return false;
            s.insert(p.second);
        }
        return true;
    }
};