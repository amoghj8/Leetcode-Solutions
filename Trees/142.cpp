// 142. Linked List Cycle II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) {
                cycle = true;
                break;
            }
        }
        if(!cycle)
            return nullptr;
        fast = head;
        while(fast!=slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};