class Solution {
private:
    vector<int> dp;
    vector<vector<int>> jobs;
    int n;
public:
    int getNextTime(int start, int key){
        int l = start, r = n-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(jobs[m][0] >= key){
                if(jobs[m-1][0] >= key) r = m - 1;
                else return m;
            }
            else if(jobs[m][0] < key) l = m + 1;
        }
        
        return -1;
    }
    
    
    int solve(int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int next = getNextTime(i, jobs[i][1]);
        
        if(next == -1) return dp[i] = max(jobs[i][2], solve(i+1));
        return dp[i] = max(solve(i+1), jobs[i][2] + solve(next));
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        dp.resize(startTime.size(),-1);
        n = startTime.size();
        for(int i=0; i<profit.size(); i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(),jobs.end());
        
        return solve(0);
    }
};