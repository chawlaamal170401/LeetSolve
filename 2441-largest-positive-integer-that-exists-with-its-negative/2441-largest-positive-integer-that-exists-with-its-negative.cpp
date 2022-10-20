class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = INT_MIN;
        
        for(int x: nums){
            if(x > 0 and ans < x and s.count(-1*x)) ans = x;
        }
        
        return ans == INT_MIN ? -1 : ans;
        
    }
};