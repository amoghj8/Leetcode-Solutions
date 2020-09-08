// 1309. Decrypt String from Alphabet to Integer Mapping

class Solution {
public:
    string freqAlphabets(string s) {
        string result="";
        for(int i=s.size()-1;i>-1;i--) {
            if(s[i]=='#') {
                string temp = string(1,s[i-2])+string(1,s[i-1]);
                int val = stoi(temp);
                result+= string(1, (char)(val-1+'a'));
                i-=2;
            }
            else {
                result += string(1,(char)('a'+s[i]-'1'));
            }
        }
        
        reverse(result.begin(),result.end());
        return result;
    }
};