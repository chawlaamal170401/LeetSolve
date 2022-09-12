class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        string ans = "";
        char c = 'a';
        for(char ch: key){
            if(ch == ' ') continue;
            else {
                if(mp.count(ch)) continue;
                else {
                    mp[ch] = c;
                    c++;
                }
            }
        }
        
        for(char ch: message){
            if(ch == ' ') ans += ' ';
            else{
                ans += mp[ch];
            }
        }
        return ans;
    }
};