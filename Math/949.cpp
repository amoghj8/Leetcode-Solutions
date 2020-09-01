// 949. Largest Time for Given Digits

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string s = "";
        for(auto num:A) {
            s+=to_string(num);
        }
        sort(s.begin(),s.end());
        if(s>"2359")
            return "";
        string result="";
        do{
            int hr = stoi(s.substr(0,2));
            int mins = stoi(s.substr(2,4));
            if(hr<24&& mins<=59) {
                result = s.substr(0,2)+":"+s.substr(2,4);
            }
        }while(next_permutation(s.begin(),s.end()) && s<="2359");
        return result;
    }
};