class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int r_pos = n+1, l_pos = -1;
        string ans = dominoes;
        
        vector<int> left_r_dis(n + 1, 0);
        vector<int> right_l_dis(n + 1, 0);
        
        for(int i=0; i<n; i++) {
            if(dominoes[i] == 'R') r_pos = i;
            else if(dominoes[i] == 'L') r_pos = n + 1;
            left_r_dis[i] = r_pos == n+1 ? n+1 : i-r_pos;
        }
        
        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L') l_pos = i;
            else if(dominoes[i] == 'R') l_pos = -1;
            right_l_dis[i] = l_pos == -1 ? n+1 : l_pos-i;
        }
        
        for(int i=0; i<n; i++){
            if (left_r_dis[i] < right_l_dis[i]) ans[i] = 'R';
            else if (left_r_dis[i] > right_l_dis[i]) ans[i] = 'L';
        }

        return ans;
    } 
};