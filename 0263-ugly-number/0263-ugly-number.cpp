class Solution {
public:
    bool isUgly(int n){
        if (n < 1) return false;

        vector<int> primes = {2, 3, 5};
        for (int p: primes) while (n % p == 0) n /=p;
        
        return n == 1;
    }
};