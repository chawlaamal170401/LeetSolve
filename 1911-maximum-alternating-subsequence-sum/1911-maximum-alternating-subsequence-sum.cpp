class Solution {
    vector<vector<long long>> dp;
public:
    long long solve(vector<int>& nums, int i, int n, bool even){
        
        if(i >= n) return 0;
        
        if(dp[i][even] != -1) return dp[i][even];
        
        long long take, notake;
        if(even){
            take = nums[i] + solve(nums, i+1, n, false);
            notake = solve(nums, i+1, n, true);
        }
        else{
            take = solve(nums, i+1, n, true) - nums[i];
            notake = solve(nums, i+1, n, false);
        }

        return dp[i][even] = max(take, notake);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<long long>(2, -1));
        
        return solve(nums, 0, n, true);
    }
};