// 1304. Find N Unique Integers Sum up to Zero

class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1) {
            return {0};
        }
        if(!(n&1)) {
            vector<int> result(n,1);
        for(int i=1;i<n;i++) {
            if(i&1) {
                result[i] = 0-result[i-1];
            }
            else {
                result[i] = i;
            }
            }
            return result;
        }
        else {
            vector<int> result(n,0);
        for(int i=1;i<n;i++) {
            if(!(i&1)) {
                result[i] = 0-result[i-1];
            }
            else {
                result[i] = i;
            }
            }
            return result;
        }
        
    }
};