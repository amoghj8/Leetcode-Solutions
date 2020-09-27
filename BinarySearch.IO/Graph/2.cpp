// Reverse Graph

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<vector<int>> solve(vector<vector<int>>& graph) {
        int rows = graph.size();
        vector<vector<int>> result(graph.size(), vector<int>());
        
        map<int,vector<int>> m;
        
        for(int i=0;i<rows;i++) {
            for(int j=0;j<graph[i].size();j++) {
                result[graph[i][j]].push_back(i);
            }
        }
        return result;
    }
};
