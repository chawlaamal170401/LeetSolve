class Solution {
public:
    int findSet(int i, vector<int> &parent){
        if(parent[i]==-1) return i; 
        return parent[i] = findSet(parent[i], parent);
    }
    
    void unionSet(int x, int y, vector<int> &parent, vector<int> &rank){
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        vector<int> parent(26, -1);
        vector<int> rank(26, 1);
        unordered_map<int, unordered_set<int>> mp;
        // sort(equations.begin(), equations.end());
        for(string eq: equations){
            int x = eq[0] - 'a';
            int y = eq[3] - 'a';
            char check = eq[1];
            
            int s1 = findSet(x, parent);
            int s2 = findSet(y, parent);
            if(check == '!'){
                if(s1==s2) return false;
                else{
                    mp[y].insert(x);
                    mp[x].insert(y);
                }
            }
            else{
                if(mp.count(x)){
                    for(auto i: mp[x]){
                        if(s2 == findSet(i, parent)) return false;
                    }
                }
                if(mp.count(y)){
                    for(auto i: mp[y]){
                        if(s1 == findSet(i, parent)) return false;
                    }
                }
                unionSet(x, y, parent, rank);
            }
            
        }
        return true;
    }
};