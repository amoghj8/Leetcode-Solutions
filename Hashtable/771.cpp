// 771. Jewels and Stones

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> st;
        for(char ch:J)
            st.insert(ch);
        int count=0;
        for(auto ch:S) {
            if(st.find(ch)!=st.end())
                count++;
        }
        return count;
    }
};