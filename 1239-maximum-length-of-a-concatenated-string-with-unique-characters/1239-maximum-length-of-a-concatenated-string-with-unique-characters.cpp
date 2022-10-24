class Solution {
    int ans = 0;
public:
    bool unique(string s){
        unordered_set<char> st;
        for(char ch: s){
            if(st.count(ch)) return false;
            st.insert(ch);
        }
        return true;
    }
    
    void solve(vector<string> &arr, int i, string temp, int n){
        if(!unique(temp)) return;
        if(ans < temp.size()) ans = temp.size();
        
        for(int j=i; j<n; j++){
            solve(arr, j+1, temp + arr[j], n);
        }
        
        return;
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
        solve(arr, 0, "", n);
        return ans;
    }
};