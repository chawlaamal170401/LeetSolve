class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        int sz = queries.size();
        
        vector<int> powers;
        vector<int> ans(sz, 0);
        
        int p = (int)log2(n);
        int num = (int)pow(2, p), sum = n;
        while(sum != 0){
            powers.push_back(num);
            sum -= num;
            if(sum){
                p = (int)log2(sum);
                num = (int)pow(2, p);
            } 
        }
        
        
        sort(powers.begin(), powers.end());
        
        for(int i=0; i<sz; i++){
            int left = queries[i][0];
            int right = queries[i][1];
            long long int val = 1;
            for(int j=left; j<=right; j++){
                val = (val * powers[j]) % mod;
            }
            ans[i] = val % mod;
        }
        return ans;
    }
};