// 202. Happy Number

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> um;
        while(n!=1) {
            int temp = n;
            int sum = 0;
            while(temp) {
                int val = temp%10;
                sum+= pow(val,2);
                temp/=10;
            }
            if(um.find(sum)!=um.end()) {
                return false;
            }
            else {
                um[sum]++;
            }
            n=sum;
        }
        return true;
    }
};