// 1019. Next Greater Node In Linked List


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
        
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        ListNode*temp =  head;
        while(temp) {
            result.push_back(temp->val);
            temp = temp->next;
        }
        stack<int> st;
        st.push(0);
        for(int i=1;i<result.size();i++) {
            if(result[i]<result[st.top()]) {
                st.push(i);
            }
            else {
                while(!st.empty() && result[i]>result[st.top()]) {
                    result[st.top()] = result[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()) {
            result[st.top()] = 0;
            st.pop();
        }
        return result;
    }
    
};