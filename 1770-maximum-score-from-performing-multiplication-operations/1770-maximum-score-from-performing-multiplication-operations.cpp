class Solution {
private: 
    vector<vector<int>> dp;
public:
    int helper(int index,vector<int>& nums, vector<int>& multi, int start) {    
       
        int end = nums.size()-1-(index-start);
        if(index== multi.size())  return 0;
       
        if (dp[index][start] != INT_MIN) 
            return dp[index][start];

       int op1 = multi[index]*nums[start] + helper(index+1, nums,multi, start+1);
       int op2 = multi[index]*nums[end] + helper(index+1, nums, multi, start);
       
       return dp[index][start] = max(op1, op2);
       
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n= nums.size();
        int m= multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        
        return helper(0, nums, multipliers, 0);
    }
};