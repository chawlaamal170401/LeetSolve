class Solution {
public:
     int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 0) return 0;
        
        map<long long int, set<long long int>> mp;
        map<pair<long long,long long>, long long> dp;
        long long int result = 0;

        for(int i=0; i<n; i++)
            mp[nums[i]].insert(i);
         
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                long long int d = nums[i]*1LL - nums[j];
                long long int prev = nums[j]*1LL - d;
                if (mp.count(prev)) {
                    auto st = mp[prev];
                    auto end = st.lower_bound(j);
                    int nums = 0;
                    for(auto p=st.begin(); p!=end; p++) nums++;
                    
                    if (nums >= 1) 
                        dp[{i, d}] += dp[{j, d}] + nums;
                }
            }
        }
         
        for(auto pr: dp) result += pr.second;
        
        return result;
    }
};