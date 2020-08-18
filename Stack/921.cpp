// 921. Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string S) {
        int total = 0;
        stack<char> st;
        for(auto ch: S) {
            if(ch=='(')
                st.push(ch);
            else if(ch==')') {
                if(!st.empty() && st.top()=='(') {
                    st.pop();
                    continue;
                }
                st.push(ch);
            }
        }
        total+=st.size();
        return total;
    }
};