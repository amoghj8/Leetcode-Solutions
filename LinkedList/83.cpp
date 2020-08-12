// 83. Remove Duplicates from Sorted List

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* temp = head;
        
        while(temp) {
            if(temp->next && temp->next->val==temp->val) {
                 while(temp->next && temp->val==temp->next->val ) {
                    ListNode* temp2 = temp->next;
                    temp->next = temp->next->next;
                    delete temp2;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};