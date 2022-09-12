class Solution {
public:
    string defangIPaddr(string s) {
        string ans = "";
        for(int i=0; s[i]!='\0'; i++){
            if(s[i] == '.'){
                ans += "[.]";
            }else ans += s[i];
        }
        return ans;
    }
};