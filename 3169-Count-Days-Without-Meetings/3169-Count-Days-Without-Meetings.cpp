class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {    
        sort(meetings.begin(), meetings.end());
        int start = meetings[0][0];
        int end = meetings[0][1];
        int freeDays = 0;
        freeDays = max(0, meetings[0][0]-1);
       
        for(int i = 1; i<meetings.size(); ++i){
            freeDays += max(0, meetings[i][0]-end-1);
            end = max(end, meetings[i][1]); 
        }
        freeDays += max(0, days-end);
        return freeDays;
    }
};