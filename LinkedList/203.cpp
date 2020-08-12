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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) {
            return head;
        }
        ListNode* temp = head;
        while(temp && temp->next) {
            if(temp->next->val==val) {
                while(temp->next && temp->next->val == val)
                {
                ListNode* temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                }
            }
            temp = temp->next;
        }
        if(head->val==val) {
            ListNode *temp2 = head;
            head = head->next;
            delete temp2;
        }
        return head;
    }
};