class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> o1, o2, e1, e2;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i] % 2) o1.push_back(nums[i]);
            else e1.push_back(nums[i]);
            if(target[i] % 2) o2.push_back(target[i]);
            else e2.push_back(target[i]);
        }
        
        sort(o1.begin(), o1.end());
        sort(o2.begin(), o2.end());
        sort(e1.begin(), e1.end());
        sort(e2.begin(), e2.end());
        
        int k = o1.size(), m = e1.size();
        long long int ans = 0;
        
        for(int i=0; i<k; i++){
            if(o2[i] > o1[i]) ans += (o2[i] - o1[i]);
        }
        
        for(int i=0; i<m; i++){
            if(e2[i] > e1[i]) ans += (e2[i] - e1[i]);
        }
        return ans/2;
    }
};