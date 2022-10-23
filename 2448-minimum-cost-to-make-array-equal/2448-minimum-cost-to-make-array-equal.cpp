#define ll long long int
class Solution {
public:
    ll solve(vector<int> &nums, vector<int> &cost, ll k){
        ll ans = 0, n = nums.size();
        
        for(int i=0; i<n; i++){
            ans += abs(nums[i] - k)*cost[i];
        }
        return ans;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll s = *min_element(nums.begin(), nums.end());
        ll e = *max_element(nums.begin(), nums.end());
        
        while(s < e){
            ll mid = s + (e-s)/2;
            
            ll lSum = solve(nums, cost, mid);
            ll rSum = solve(nums, cost, mid+1);
            
            if(lSum < rSum) e = mid;
            else s = mid + 1;
        }
        return solve(nums, cost, s);
    }
};