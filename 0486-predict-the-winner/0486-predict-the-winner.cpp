class Solution {
public:
    int solve(vector<int> &nums, int l, int h, int turn){
        if(l == h) return turn * nums[l];
        int a = turn*nums[l] + solve(nums, l+1, h, -turn);
        int b = turn*nums[h] + solve(nums, l, h-1, -turn);
        
        return turn*max(turn*a, turn*b);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1, 1) >= 0;
    }
};