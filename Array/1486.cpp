// 1486. XOR Operation in an Array

class Solution {
public:
    int xorOperation(int n, int start) {
        int result=start;
        for(int i=1;i<n;i++) {
            start += 2;
            result ^= start;
        }
        return result;
    }
};