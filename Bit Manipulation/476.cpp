// 476. Number Complement
class Solution {
public:
    int findComplement(int N) {
        if(!N)
            return 1;
        bitset<32> bt(N);
        string rep = bt.to_string();
        int i=0;
        while(rep[i]=='0') {
            rep.erase(rep.begin()+i);
        }
        int temp =  0;
        for(int i=0;i<rep.size();i++) {
            temp <<=1;
            temp |= (1^(rep[i]-'0'));
        }
        return temp;
    }
};