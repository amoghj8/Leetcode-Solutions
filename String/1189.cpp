class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> um;
        for(int i=0;i<text.size();i++) {
            if(text[i]!='b' && text[i]!='a' && text[i]!='l' && text[i]!='o' && text[i]!='n') {
                continue;
            }
            um[text[i]]++;
        }
        if(um.size()<5)
            return 0;
        
        int singleCount = min({um['b'],um['a'],um['n']});
        int doubleCount = min(um['l'],um['o']);
        return min(singleCount,doubleCount/2);
    }
};