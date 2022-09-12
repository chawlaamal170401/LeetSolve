class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = typed.size(), m = name.size();
        int i=0, j=0;
        
        while(j<n){
            if(i<m and typed[j]==name[i]) i+=1, j+=1;
            else if(j>0 and typed[j]==name[i-1]) j+=1;
            else return false;
        }
        return i==m;
    }
};