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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* temp1 = head->next;
        while(curr && curr->next) {
            ListNode* temp = curr->next->next;
            if(prev) {
                prev->next = curr->next;    
            }
            curr->next->next = curr;
            curr->next = temp;
            prev = curr;
            curr = curr->next;
        }
        head = temp1;
        return head;
    }
};