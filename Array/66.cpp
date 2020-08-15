// 66. Plus One

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i=digits.size()-1;i>-1;i--) {
            int sum=0;
            if(i==digits.size()-1) {
                sum = carry + digits[i]+1;
            }
            else {
                sum = carry +digits[i];
            }
            digits[i] = sum %10;
            carry = sum/10;
        }
        if(carry) {
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};