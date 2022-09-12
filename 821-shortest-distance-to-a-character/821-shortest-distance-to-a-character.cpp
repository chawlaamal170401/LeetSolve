class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, n);
        vector<int> pos;
        
        for(int i=0; i<n; i++){
            if(s[i] == c)
                pos.push_back(i);
        }
        
        for(int i=0; i<n; i++){
            if(s[i] == c) ans[i] = 0;
            else{
                for(int x: pos) ans[i] = min(ans[i], abs(x-i));
            }
        }
        return ans;
    }
};