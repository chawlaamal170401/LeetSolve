class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), maxi = INT_MIN;
        int len = 0, maxLen = 0;
        for(int x: nums) maxi = max(maxi, x);
        
        for(int x: nums){
            if(x == maxi){
                len += 1;
                maxLen = max(maxLen, len);
            }
            else len = 0;
        }
        return maxLen;
    }
};