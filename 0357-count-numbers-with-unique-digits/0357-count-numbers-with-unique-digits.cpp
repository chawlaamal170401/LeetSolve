class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 10, temp = 9, cnt = 9;
        for(int i=0; i<n-1; i++){
            temp *= cnt;
            ans += temp;
            cnt -= 1;
        }
        return ans;
    }
};