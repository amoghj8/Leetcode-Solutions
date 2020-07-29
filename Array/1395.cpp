// 1395. Count Number of Teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int total=0;
        for(int i=0;i<rating.size();i++) {
            for(int j=i+1; j<rating.size();j++) {
                for(int k=j+1; k<rating.size();k++) {
                    if((rating[i]>rating[j]) && (rating[j]>rating[k])){
                        total +=1;
                    }
                    else if((rating[i]<rating[j]) && (rating[j]<rating[k])) {
                        total+=1;
                    }
                }
            }
        }
        return total;
    }
};