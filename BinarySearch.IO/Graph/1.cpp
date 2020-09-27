// No New Friends

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(int n, vector<vector<int>>& friends) {
        vector<bool> visited(n,false);
        map<int,list<int>> m;
        
        int row = friends.size();
        int col = friends[0].size();
        
        for(int i=0;i<row;i++) {
            m[friends[i][0]].push_back(friends[i][1]);
        }
        
        for(int i=0;i<row;i++) {
            dfs(friends,visited,m,friends[i][0]);
        }
        
        for(auto frnd:visited) {
            if(!frnd)
                return false;
        }
        
        return true;
    }
    
    private:
    void dfs(vector<vector<int>>& friends, vector<bool> &visited, map<int,list<int>>&m,int index) {
        
        if(visited[index])
            return;
        
        visited[index] = true;
        for(auto itr=m[index].begin();itr!=m[index].end();itr++) {
            dfs(friends,visited,m,*itr);
        }
    }
};
