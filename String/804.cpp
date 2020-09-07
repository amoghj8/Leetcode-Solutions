// 804. Unique Morse Code Words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseVec = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> morseSet;
        for(int i=0;i<words.size();i++) {
            string temp="";
            for(auto ch:words[i]) {
                temp+= morseVec[ch-'a'];
            }
            morseSet.insert(temp);
        }
        return morseSet.size();
    }
};