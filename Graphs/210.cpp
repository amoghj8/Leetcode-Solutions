// 210. Course Schedule II

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses, 0);
        vector<int> result;
        map<int,list<int>> m;
            for(auto req:prerequisites) {
                inDegrees[req[0]]++;
                m[req[1]].push_back(req[0]);
            }
            queue<int> startSet;
            for(int i=0;i<numCourses;i++) {
                if(!inDegrees[i])
                    startSet.push(i);
            }
            if(!startSet.size())
                return {};
        
        int edgeCount = prerequisites.size();
        while(!startSet.empty()) {
            int top = startSet.front();
            startSet.pop();
            for(auto node:m[top]){
                edgeCount--;
                if(--inDegrees[node] == 0) {
                    startSet.push(node);
                }
            }
            result.push_back(top);
        }
        
        if(edgeCount)
            return {};
        else 
            return result;
    }
};