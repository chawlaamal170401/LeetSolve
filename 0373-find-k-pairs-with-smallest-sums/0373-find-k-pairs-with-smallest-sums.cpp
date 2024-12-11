class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int x: nums1){
            pq.push({x+nums2[0], 0});
        }

        while(k-- && pq.size()){
            int sum = pq.top().first;
            int idx = pq.top().second;

            ans.push_back({sum-nums2[idx], nums2[idx]});
            pq.pop();

            if(idx + 1 < nums2.size()){
                pq.push({sum-nums2[idx] + nums2[idx+1], idx+1});
            }
        }
        return ans;
    }
};