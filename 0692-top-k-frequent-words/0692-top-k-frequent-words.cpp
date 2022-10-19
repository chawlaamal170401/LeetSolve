typedef pair<int, string> ps;

struct cmp{
    bool operator()(const ps a, const ps b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        
        unordered_map<string, int> mp;
        priority_queue<ps, vector<ps>, cmp> pq;
        vector<string> ans;

        for(string word: words){
            mp[word]++;
        }
                
        for(auto p: mp){
            pq.push({p.second, p.first});
        }
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};