class Solution {
public:
    int gcd(int a, int b){
        if(a == 0) return b;
        return gcd(b%a, a);
    }
    
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), cnt = 0;
        
        for(int i=0; i<n; i++){
            ans = 0;
            for(int j=i; j<n; j++){
                ans = gcd(nums[j], ans);
                if(ans == k) cnt += 1;
            }
        }
        return cnt;
    }
};