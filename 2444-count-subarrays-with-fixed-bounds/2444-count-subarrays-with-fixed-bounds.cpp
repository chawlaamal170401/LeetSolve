#define ll long long int
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans = 0, ptr = -1, min_ptr = -1, max_ptr = -1, n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i] < minK or nums[i] > maxK) ptr = i;
            if(nums[i] == minK) min_ptr = i;
            if(nums[i] == maxK) max_ptr = i;
            ans += max(0LL, min(min_ptr, max_ptr) - ptr);
        }
        return ans;
    }
};