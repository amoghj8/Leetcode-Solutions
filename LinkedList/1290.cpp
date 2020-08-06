// 1290. Convert Binary Number in a Linked List to Integer

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
    int getDecimalValue(ListNode* head) {
        string s;
        ListNode* temp = head;
        while(temp!=nullptr) {
            s+=to_string(temp->val);
            temp = temp->next;
        }
        bitset<32> bt(s);
        return bt.to_ulong();
        
    }
};