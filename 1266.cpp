// 1266. Minimum Time Visiting All Points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total = 0;
        for(int i=0; i<points.size()-1;i++) {
            int dist_x = abs(points[i][0] - points[i+1][0]);
            int dist_y = abs(points[i][1] - points[i+1][1]);
            total+= max(dist_x, dist_y);
        }
        return total;
    }
};