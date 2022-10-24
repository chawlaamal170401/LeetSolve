class Solution {
public:
    int solve(vector<int> &nums){
        int sum = 0, max_sum = INT_MIN, curr_sum = 0;

        for(int x: nums){
            if(curr_sum < 0) curr_sum = 0;
            curr_sum += x;
            max_sum = max(curr_sum , max_sum);
        }
        return max_sum;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int max1 = solve(nums);
        
        if(max1 < 0) return max1;
        
        for(int &n: nums){
            sum += n;
            n = -1*n;
        }
        int max2 = solve(nums) + sum;
        
        return max(max1, max2);
    }
};