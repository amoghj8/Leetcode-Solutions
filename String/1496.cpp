// 1496. Path Crossing
class Solution {
public:
    bool isPathCrossing(string path) {
        multimap<int,int> mm;
        mm.insert(pair<int,int> (0,0));
        pair<int,int> curr = make_pair(0,0);
        for(auto ch:path) {
            curr = getLoc(ch,curr);
            if(helper(curr, mm))
                return true;
            else {
                mm.insert(curr);
            }
        }
        return false;
        
    }
private:
    bool helper(pair<int,int>&loc, multimap<int,int> &mm) {
        for(auto itr=mm.begin();itr!=mm.end();itr++) {
            if(itr->first==loc.first && itr->second==loc.second)
                return true;
        }
        return false;
    }
    
    pair<int,int> getLoc(char ch, pair<int,int>& p) {
        if(ch=='N') {
            ++p.second;
        }
        else if(ch=='S') {
            --p.second;
        }
        else if(ch=='E') {
            ++p.first;
        }
        else {
           --p.first; 
        }
        return p;
    }
};