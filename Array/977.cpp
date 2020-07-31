// 977. Squares of a Sorted Array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        sort(A.begin(), A.end(), [](int a, int b) {
            return abs(a)<abs(b);
        });
        transform(A.begin(),A.end(),A.begin(), [](int a) {
            return pow(a,2);
        });
        return A;
    }
};