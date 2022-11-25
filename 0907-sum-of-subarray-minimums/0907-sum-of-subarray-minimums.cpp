class Solution {
public:
    int sumSubarrayMins(vector<int>& n) {
        vector<long long int> s, sums(n.size(),0);
        long long int j, res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n.size(); ++i){
            while (!s.empty() && n[s.back()] > n[i])
                s.pop_back();
            j = s.empty() ? -1 : s.back();
            
            sums[i] = ((j>=0 ? sums[j] : 0) + (i-j)*n[i]) % mod;
            s.push_back(i);
        }

        for(int i=0; i<sums.size(); i++)
            res = (res + sums[i]) % mod;
        
        return res;
    }
};