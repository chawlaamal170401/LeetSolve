class Solution {
    const int mod = 1e9 + 7;
    int ans = 0;
    vector<vector<vector<int>>> dp;
public:
    int solve(vector<vector<int>> &grid, int n, int m, int k, int sum){
        if(n == 0 and m == 0){
            if(sum % k == 0) return 1;
            return 0;
        }
        
        if(dp[n][m][sum] != -1) return dp[n][m][sum];
        
        int l = 0, r = 0;
        
        if(n >= 1)
            l = solve(grid, n-1, m, k, (sum + grid[n-1][m]) % k);
        if(m >= 1)
            r = solve(grid, n, m-1, k, (sum + grid[n][m-1]) % k);
        
        return dp[n][m][sum] = (l + r) % mod;
    }
    
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        dp.assign(n, vector<vector<int>>(m , vector<int>(k+1, -1)));
        
        return solve(grid, n-1, m-1, k, grid[n-1][m-1] % k);
    }
};