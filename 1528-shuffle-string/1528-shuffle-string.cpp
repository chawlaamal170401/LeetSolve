class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans(n, 'a');
        
        for(int i=0; i<n; i++){
            char ch = s[i];
            int idx = indices[i];
            ans[idx] = ch;
        }
        return ans;
    }
};