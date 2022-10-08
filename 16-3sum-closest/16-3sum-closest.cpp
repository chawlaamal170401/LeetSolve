class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int t = nums[i];
            int j=i+1, k=n-1;
            
            while(j<k){
                int sum = t+nums[j]+nums[k];
                if(sum<=target) j++;
                else k--;
                mp[sum]=abs(target-sum);
            }
            
        }
        int d = INT_MAX;
        int ans = -2000;
        for(auto p: mp){
            if(p.second<d){
                ans=p.first;
                d=p.second;
            }
        }
        
        return ans;
    }
};