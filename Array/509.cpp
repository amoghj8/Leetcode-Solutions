// 509. Fibonacci Number

class Solution {
public:
    int fib(int N) {
        if(N==0) {
            return 0;
        }
        else if(N==1) {
            return 1;
        }
        vector<int> dp(N+1,1);
        dp[0]=0;
        
        for(int i=2;i<N+1;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[N];
    }
};