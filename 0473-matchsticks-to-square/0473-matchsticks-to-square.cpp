class Solution {
    bool solve(int idx, int bucketSize, vector<int> &dp, vector<int> &matchsticks){
        if(idx == matchsticks.size()){
            return dp[0] == dp[1] && dp[1] == dp[2] && dp[2] == dp[3];
        }

        for(int i=0; i<4; i++){
            if(dp[i] + matchsticks[idx] > bucketSize) continue;

            int j=i;

            while(--j >= 0){
                if(dp[i] == dp[j]) break;
            }

            if(j != -1) continue;

            dp[i] += matchsticks[idx];
            if(solve(idx + 1, bucketSize, dp, matchsticks)) return true;
            dp[i] -= matchsticks[idx];
        }
        return false;
    }



public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        vector<int> dp(4, 0);

        for(int stick: matchsticks) sum += stick;

        if(sum == 0 || sum % 4) return false;

        sort(matchsticks.begin(), matchsticks.end());

        return solve(0, sum/4, dp, matchsticks);

    }
};