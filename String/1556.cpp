// 1556. Thousand Separator

class Solution {
public:
    string thousandSeparator(int n) {
        if(n<1000) {
           return to_string(n);
        }
        string temp = to_string(n);
        reverse(temp.begin(),temp.end());
        int count = 0;
        for(int i=0;i<temp.size();i++) {
            if(count==3) {
                temp.insert(i,".");
                count=-1;
            }
            ++count;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};