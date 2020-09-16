// Ternary Expression Parser

class Solution {
public:
    /**
     * @param expression: a string, denote the ternary expression
     * @return: a string
     */
    string parseTernary(string &expression) {
        std::stack<char> st ;
        for(int i=expression.size();i>-1;i--) {
            char ch = expression[i];
            if(!st.empty() && st.top()=='?') {
                st.pop();
                char top_left =  st.top();
                st.pop();
                st.pop();
                char top_right = st.top();
                st.pop();
                if(ch=='T')
                    st.push(top_left);
                else
                    st.push(top_right);
            }
            else {
                st.push(ch);
            }
        }
        return string(1,st.top());
    }
};