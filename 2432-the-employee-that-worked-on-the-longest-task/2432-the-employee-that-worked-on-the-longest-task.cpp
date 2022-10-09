class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = 1e9, maxi = -1e9;
        
        for(int i=0; i<logs.size(); i++){
            if(i==0){
                maxi = logs[i][1];
                ans = logs[i][0];
            }
            else if(maxi < (logs[i][1] - logs[i-1][1])){
                maxi = logs[i][1] - logs[i-1][1];
                ans = logs[i][0];
            }
            else if(maxi == (logs[i][1] - logs[i-1][1]))
                ans = min(ans, logs[i][0]);
        }
        return ans;
    }
};