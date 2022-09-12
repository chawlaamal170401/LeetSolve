class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, i = 0, j = 1;
        
        for(int k=1; k<s.size(); k++){
            if(s[k-1] != s[k]){
                ans += min(i, j);
                i = j;
                j = 1;
            }
            else j+=1;
        }
        return ans + min(i, j);
    }
};