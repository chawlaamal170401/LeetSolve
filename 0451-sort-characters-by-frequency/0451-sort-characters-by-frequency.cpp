struct cmp{
    bool operator()(pair<char,int> a, pair<char, int> b){
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        if(s=="") return "";
        int n = s.size();
        unordered_map<char, int> mp;
        
        for(char c: s){
            mp[c]++;
        }
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq; 
        
        for(auto p: mp){
            pq.push({p.first, p.second});
        }
        
        string ans="";
        
        while(pq.size()){
            pair<char, int> p = pq.top();
            int rep = p.second;
            char ch = p.first;
            string temp="";
            while(rep--){
                temp += ch;
            }
            ans += temp;
            pq.pop();
        }
        return ans;
    }
};