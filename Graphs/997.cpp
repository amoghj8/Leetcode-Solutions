// 997. Find the Town Judge

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        if(!trust.size() && N==1)
            return 1;
        
        
        map<int,set<int>> judges;
        set<int> potentials;
        for(auto rel:trust) {
            judges[rel[1]].insert(rel[0]);
        }
                
        for(auto itr=judges.begin();itr!=judges.end();itr++) {
            if(itr->second.size()==N-1) {
                potentials.insert(itr->first);
            }
        }
        
        if(!potentials.size())
            return -1;
        
        for(auto t:trust) {
            if(potentials.find(t[0])!=potentials.end()) {
                potentials.erase(t[0]);
            }
        }
        
        if(!potentials.size())
            return -1;
        else
            return *potentials.begin();
    }
};