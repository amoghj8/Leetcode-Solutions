// 1450. Number of Students Doing Homework at a Given Time

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int total = 0;
        for(int i=0;i<startTime.size();i++) {
            if(startTime[i]<=queryTime && queryTime<=endTime[i]) {
                total+=1;
            }
        }
        return total;
        
    }
};