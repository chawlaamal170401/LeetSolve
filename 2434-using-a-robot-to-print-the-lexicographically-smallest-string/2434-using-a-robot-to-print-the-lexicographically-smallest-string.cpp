class Solution {
public:
    string robotWithString(string s) {
        stack<char> st;
        string ans = "";
        string mins = s;
        
        int n = s.size();
        mins[n-1] = s[s.length()-1];
        
        for(int i=n-2; i>=0; i--){
            char c;
            if(mins[i+1] < s[i]) c = mins[i+1];
            else c = s[i];
            mins[i] = c;
        }
        
        for(int i=0; i<n; i++){
            if(s[i] != mins[i]){
                while(!st.empty() and st.top() <= mins[i]){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
            else{
               while(!st.empty() and st.top() <= s[i]){
                    ans.push_back(st.top());
                    st.pop();
                }
                ans.push_back(s[i]);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};