class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        
        int cnt = 1;
        while(cnt*cnt <= n){
            int sq = cnt*cnt;
            for(int i=sq; i<=n; i++){
                dp[i] = min(1+dp[i-sq], dp[i]);
            }
            cnt += 1;
        }
        return dp[n];
    }
};