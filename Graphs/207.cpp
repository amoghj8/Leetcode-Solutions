// 207. Course Schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,list<int>> adjList;
        for(int i=0;i<prerequisites.size();i++) {
                adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        if(isCyclic(adjList, numCourses))
            return false;
        return true;
    }
private:
    bool isCyclic(map<int,list<int>> &adjList, int vertices) {
        vector<bool> isVisited(vertices, false);
        bool flag = false;
        for(auto node:adjList) {
            isVisited[node.first] = true;
            for(auto prereq:node.second) {
               flag = isCyclicUtil(adjList,isVisited, prereq);
                if(flag)
                    return true;
            }
            isVisited[node.first] = false;
        }
        return false;
    }
    
    bool isCyclicUtil(map<int,list<int>> &adjList, vector<bool> &isVisited, int curr) {
        
        if(isVisited[curr])
            return true;
        
        if(adjList.find(curr)==adjList.end())
            return false;
        
        isVisited[curr] = true;
        bool flag = false;
        for(auto node:adjList[curr]) {
            flag = isCyclicUtil(adjList, isVisited, node);
            if(flag)
                return true;
        }
        isVisited[curr] = false;
        return false;
    }
}; 