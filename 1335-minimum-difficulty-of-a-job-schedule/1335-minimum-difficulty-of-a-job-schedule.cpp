#define INF 1e7
int n, dp[305][15];
class Solution {
public:
    int dfs(int i,int d,vector <int> &jd){
        if(i == n and d == 0) return 0;
        if(i == n or d == 0 or n-i < d) return INF;
        if(dp[i][d] != -1) return dp[i][d];
        
        int ans = INF, maxele = -INF;
        
        for(int j=i; j<n; j++){   
            maxele=max(maxele,jd[j]); 
            ans=min(ans,maxele+dfs(j+1,d-1,jd)); 
        }
        return dp[i][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        if(n<d) return -1;
        memset(dp,-1,sizeof(dp));
        int ans = dfs(0,d,jobDifficulty);
        return ans;
    }
};