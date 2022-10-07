class MyCalendarThree {
    int maxCnt = 0;
    map<int, int> mp; 
public:    
    MyCalendarThree(){}
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int cnt = 0;
        for (auto it: mp) {
            cnt += it.second;
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;   
    }
};