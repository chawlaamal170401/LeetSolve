class CombinationIterator {
    vector<string> map;
    int ptr;
    string val;
public:
    void solve(string s, int i, int n, string temp){
        if(i>=s.size()){
            if(n==0){
                map.push_back(temp);
                return;
            }
            return;
        }
        if(n==0){
            map.push_back(temp);
            return;
        }
        temp.push_back(s[i]);
        solve(s, i+1, n-1, temp);
        temp.pop_back();
        solve(s, i+1, n, temp);
        return;
    }
    
    CombinationIterator(string characters, int combinationLength) {
        solve(characters, 0, combinationLength, "");
        ptr = 0;
        val = "";
    }
    
    string next() {
        if(ptr < map.size()){
            val = map[ptr];
            ptr += 1;
        }
        return val;
    }
    
    bool hasNext() {
        return ptr < map.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */