class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        // vector<bool> visited(trainers.size(), false);
        int n = players.size(), m = trainers.size();
        int ans = 0, i=n-1, j=m-1;
        
        while(i>=0 and j>=0){
            if(players[i] > trainers[j]){
                i--;
            }
            else{
                i--;
                j--;
                ans += 1;
            }
        }
        return ans;
    }
};