// 1374. Generate a String With Characters That Have Odd Counts

class Solution {
public:
    string generateTheString(int n) {
        string result;
        if(n&1) {
            for(int i=0;i<n;i++) {
                result+= "a";
            }
        }
        else {
            result += "a";
            for(int i=0;i<n-1;i++) {
                result+=  "b";
            }
        }
        return result;
    }
};