class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans(n+1);
        
        int l = 0, h = n;
        
        for(int i=0; i<n; i++){
            if(s[i] == 'I'){
                ans[i] = l;
                l+=1;
            }
            else{
                ans[i] = h;
                h-=1;
            }
        }
        ans[n] = l;
        return ans;
    }
};