class Solution {
public:
    string makeGood(string s) {
        bool flag = false;
        
        while(s.size() > 1){
            flag = false;
            for(int i=0; i<s.size()-1; i++){
                char curr = s[i];
                char next = s[i+1];
            
            
                if(abs(curr - next) == 32){
                    s = s.substr(0, i) + s.substr(i+2);
                    flag = true;
                    break;
                }
            }
            if(!flag) break;
        }
        
        return s;
    }
};