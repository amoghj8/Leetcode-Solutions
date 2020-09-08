// 824. Goat Latin

class Solution {
public:
    string toGoatLatin(string S) {
        int index=1;
        string result;
        istringstream ss(S);
        string word;
        while(ss>>word) {
            if(checkVowelUpper(word[0]) || checkVowelLower(word[0])) {
                result+=word+"ma";
                
            }
            else {
                result += word.substr(1)+ word[0] + "ma";
            }
            for(int i=0;i<index;i++) {
                    result+="a";
            }
            ++index;
            result+=" ";
        }
        return result.substr(0,result.size()-1);
    }
private:
    bool checkVowelUpper(char ch) {
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return true;
        return false;
    }
    
    bool checkVowelLower(char ch) {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }
};