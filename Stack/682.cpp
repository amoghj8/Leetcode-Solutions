// 682. Baseball Game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int sum = 0;
        for(int i=0;i<ops.size();i++) {
            if(ops[i]=="C") {
                sum -= st.top();
                st.pop();
            }
            else if(ops[i]=="+") {
                int temp2 = st.top();
                st.pop();
                int temp1 = st.top();
                st.pop();
                int tempSum = temp1+temp2;
                sum+= tempSum;
                st.push(temp1);
                st.push(temp2);
                st.push(tempSum);
            }
            else if(ops[i]=="D") {
                sum += 2*st.top();
                st.push(2*st.top());
            }
            else {
                st.push(stoi(ops[i]));
                sum +=stoi(ops[i]);
            }
        }
        return sum;
    }
};