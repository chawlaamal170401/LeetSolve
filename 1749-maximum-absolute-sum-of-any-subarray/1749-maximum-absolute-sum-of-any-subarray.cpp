class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, maxSum = 0, minSum = 0;
        
        for(int i=0; i<n; i++){
            maxSum = max(0, nums[i] + maxSum);
            minSum = min(0, nums[i] + minSum);
            ans = max({ans, maxSum, -minSum});
        }
        
        return ans;
    }
};