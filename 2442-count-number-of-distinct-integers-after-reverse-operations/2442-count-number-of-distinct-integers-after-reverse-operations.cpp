class Solution {
public:
    int reverse(int x){
        int y = 0;
        while(x){
            y = y*10 + x%10;
            x = x/10;
        }
        return y;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        
        for(int x: nums){
            int a = reverse(x);
            s.insert(a);
        }
        
        return s.size();
    }
};