class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        
        for(int i=num/2; i<=num; i++){
            string a = to_string(i);
            reverse(a.begin(), a.end());
            
            int x = stoi(a);
            
            if(x + i == num) return true;
        }
        return false;
    }
};