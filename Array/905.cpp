// 905. Sort Array By Parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        partition(A.begin(), A.end(), 
             [](int a){
                 return !(a&1);
        }
    );
        return A;
            
    }
};