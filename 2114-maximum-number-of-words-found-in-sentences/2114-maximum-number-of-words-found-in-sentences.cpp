class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = -1e9, cnt = 0;
        for(string s: sentences){
            cnt = 1;
            for(char ch: s){
                if(ch == ' ') cnt += 1;
            }
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};