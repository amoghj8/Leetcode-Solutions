// 61. Rotate List

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k)
            return head;
        ListNode* temp = head;
        int count = 1;
        while(temp->next) {
            count++;
            temp = temp->next;
        }
        k = k%count;
        temp->next = head;
        for(int i=0;i<count-k;i++) {
            temp = temp->next;
        } 
        head = temp->next;
        temp->next = nullptr;
        return head; 
    }
};