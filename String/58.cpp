// 58. Length of Last Word

class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        istringstream ss(s);
        string last;
        ss >> last;
        return last.size();
    }
};