class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int ans = 1;
        int len = 1;
        
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1] + 1){
                len += 1;
                ans = max(ans, len);
            }
            else{
                len = 1;
            }
        }
        return ans;
    }
};