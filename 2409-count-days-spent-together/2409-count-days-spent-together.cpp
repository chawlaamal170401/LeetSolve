class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> v = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int aMonth = stoi(arriveAlice.substr(0, 2));
        int aDate = stoi(arriveAlice.substr(3, 2));
        int alMonth = stoi(leaveAlice.substr(0, 2));
        int alDate = stoi(leaveAlice.substr(3, 2));
        
        int bMonth = stoi(arriveBob.substr(0, 2));
        int bDate = stoi(arriveBob.substr(3, 2));
        int blMonth = stoi(leaveBob.substr(0, 2));
        int blDate = stoi(leaveBob.substr(3, 2));
        
        if(bMonth > alMonth or blMonth < aMonth) return 0;
        if(bMonth == alMonth and bDate > alDate) return 0;
        if(blMonth == aMonth and blDate < aDate) return 0;
        
        int sMonth, sDate, eMonth, eDate;
        
        sMonth = bMonth > aMonth ? bMonth : aMonth;
        eMonth = blMonth > alMonth ? alMonth : blMonth;
        
        if(bMonth > aMonth) sDate = bDate;
        else if(bMonth == aMonth) sDate = max(aDate, bDate);
        else sDate = aDate;
        
        if(blMonth > alMonth) eDate = alDate;
        else if(blMonth == alMonth) eDate = min(alDate, blDate);
        else eDate = blDate;
        
        if(sMonth == eMonth) return (eDate - sDate) + 1;
        
        int timeSpent = (v[sMonth] - sDate) + 1;
        
        for(int i=sMonth+1; i<eMonth; i++)
            timeSpent += v[i];
        
        timeSpent += eDate;
        
        return timeSpent;
    }
};