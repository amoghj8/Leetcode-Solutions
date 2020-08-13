// 1047. Remove All Adjacent Duplicates In String

class Solution {
public:
    string removeDuplicates(string S) {
        if(S.length()==1){
            return S;
        }
        stack<char> s;
        string result;
        for(auto ch : S) {
            if(s.empty() || s.top()!=ch) {
                s.push(ch);
                continue;
            }
            while(!s.empty() && (s.top()==ch)) {
                s.pop();
            }
        }
        
        while(!s.empty()){
            result.insert(0, string(1,s.top()));
            s.pop();
        }
        
        return result;
    }
};