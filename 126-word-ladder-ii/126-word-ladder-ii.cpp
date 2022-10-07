class Solution {
private:
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    
public:
    
    void dfs(string src, vector<string> &temp){
        if(src == b){
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            return;
        }
        int steps = mp[src];
        int sz = src.size();
        for(int i=0; i<sz; i++){
            char orignal = src[i];
            for(char ch='a'; ch<='z'; ch++){
                src[i] = ch;
                if(mp.count(src) and mp[src] + 1 == steps){
                    temp.push_back(src);
                    dfs(src, temp);
                    temp.pop_back();
                }
            }
            src[i] = orignal;
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        q.push(beginWord);
        st.erase(beginWord);
        
        b = beginWord;
        mp[beginWord] = 1;

        while(!q.empty()){
            string s = q.front();
            int steps = mp[s];
            q.pop();
            int sz = s.size();
            
            if(s == endWord) break;
            
            for(int i=0; i<sz; i++){
                char orignal = s[i];
                for(char ch='a'; ch<='z'; ch++){
                    s[i] = ch;
                    if(st.count(s)){
                        q.push(s);
                        st.erase(s);
                        mp[s] = steps + 1;
                    }
                }
                s[i] = orignal;
            }   
        }
        
        if(mp.count(endWord)){
            vector<string> temp;
            temp.push_back(endWord);
            dfs(endWord, temp);
        }
        
        return ans;
    }
};