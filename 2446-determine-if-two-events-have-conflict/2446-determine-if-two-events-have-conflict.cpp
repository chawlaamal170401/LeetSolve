class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {     
        string s1 = "", s2 = "", e1 = "", e2 = "";
        
        for(int i=0; i<5; i++){
            if(i == 2) continue;
            s1 += event1[0][i];
            e1 += event1[1][i];
            s2 += event2[0][i];
            e2 += event2[1][i];
        }
        
        if(s2 < s1){
            swap(s2, s1);
            swap(e2, e1);
        }
        
        return s2 <= e1;
    }
};