// 7. Reverse Integer

class Solution {
public:
    int reverse(int x) {
        stack<int> st;
        int result=0;
        string s = to_string(x);
        if(x<0) {
            s = s.substr(1);
        }
        for(auto ch:s) {
            st.push(ch-'0');
        }
        while(!st.empty()) {
            if(result>INT_MAX/10)
                return 0;
            result = result*10+st.top();
            st.pop();
        }
        if(x<0)
            return -1*result;
        else 
            return result;
    }
};