class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), t = 0;
        int sum = (n*(n+1))/2;
        
        unordered_set<int> s;
        
        for(int x: nums){
            if(s.count(x)) ans.push_back(x);
            else{
                t += x;
                s.insert(x);
            }
        }
        
        ans.push_back(sum - t);
        return ans;
    }
};