class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> arr(n, 0);
        
        int val = 0;
        arr[0] = pref[0];
        
        for(int i=1; i<n; i++){
            val ^= arr[i-1];
            arr[i] = val ^ pref[i];
        }
        
        return arr;
    }
};