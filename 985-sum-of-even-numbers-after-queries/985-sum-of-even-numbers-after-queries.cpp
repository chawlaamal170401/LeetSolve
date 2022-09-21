class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n , 0);
        int eval = 0;
        
        for(int x: nums){
            if(x%2==0)
                eval += x;
        }
        
        for(int i=0; i<n; i++){
            int val = queries[i][0];
            int idx = queries[i][1];
            
            if(nums[idx] % 2 == 0) {
                if((nums[idx] + val) % 2 == 0){
                    nums[idx] += val;
                    eval += val;
                    ans[i] = eval;
                }
                else{
                    eval -= nums[idx];
                    nums[idx] += val;
                    ans[i] = eval;
                }
            }
            else{
                if((nums[idx] + val) % 2 == 0){
                    nums[idx] += val;
                    eval += nums[idx];
                    ans[i] = eval;
                }
                else{
                    nums[idx] += val;
                    ans[i] = eval;
                }
            }
        }
        
        return ans;
    }
};