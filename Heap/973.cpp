class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue <int, vector<int>, greater<int> > pq; 
        multimap<int,vector<int>> m;
        vector<vector<int>> result;
        for(int i=0;i<points.size();i++) {
            int temp = pow(points[i][0],2) + pow(points[i][1],2);
            m.insert(pair <int, vector<int>> (temp, {points[i][0],points[i][1]}));
            pq.push(temp);
        }
        for(int i=0;i<K;) {
            int temp = pq.top();
            int count = m.count(temp);
            auto itr = m.find(temp);
            while(count) {
                result.push_back(itr->second);
                ++i;
                --count;
                pq.pop();
                itr++;
            }
        }
        return result;
    }
};