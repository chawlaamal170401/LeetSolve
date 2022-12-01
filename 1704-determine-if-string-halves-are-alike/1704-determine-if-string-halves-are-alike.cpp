class Solution {
public:
    bool check(char ch){
        ch = tolower(ch);
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') return true;
        return false;
    }
    
    bool halvesAreAlike(string s) {
        int n = s.size()/2;
        int cnt1 = 0, cnt2 = 0;
        
        for(int i=0; i<n; i++){
            if(check(s[i])) cnt1 += 1;
            if(check(s[i+n])) cnt2 += 1;
        }
        return cnt1 == cnt2;
    }
};