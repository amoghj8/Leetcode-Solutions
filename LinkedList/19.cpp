// 19. Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while(temp) {
            length++;
            temp = temp->next;
        }
        if(n==length) {
            return head->next;
        }
        ListNode* temp2 = head;
        for(int i=1;i<length-n;i++) {
            temp2 = temp2->next;
        }
        temp2->next  = temp2->next->next;
        return head;
    }
};