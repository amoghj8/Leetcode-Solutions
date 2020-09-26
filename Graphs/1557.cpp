// 1557. Minimum Number of Vertices to Reach All Nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        for(int i=0;i<edges.size();i++) {
            visited[edges[i][1]] = true;
        }
        vector<int> result;
        for(int i=0;i<visited.size();i++) {
            if(!visited[i])
                result.push_back(i);
        }
        return result;
    }

};