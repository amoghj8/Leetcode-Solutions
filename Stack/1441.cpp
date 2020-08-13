// 1441. Build an Array With Stack Operations
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        
        for(int i=1;i<target[0];i++) {
            result.push_back("Push");
            result.push_back("Pop");
        }
        
        for(int j=0, k=target[j];j<target.size();) {
            if(target[j]==k) {
                result.push_back("Push");
                j++;
            }
            else {
                result.push_back("Push");
                result.push_back("Pop");
            }
            k++;
        }
        
        return result;
    }
};

