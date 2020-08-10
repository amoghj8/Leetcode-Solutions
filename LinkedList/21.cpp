// 21. Merge Two Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) {
            return l2;
        }
        else if(!l2) {
            return l1;
        }
        ListNode* newPtr = new ListNode;
        ListNode* newHead = newPtr;
        while(l1&&l2) {
            ListNode *&temp = l1->val > l2->val ? l2: l1;
            newPtr->next = temp;
            temp = temp->next;
            newPtr = newPtr->next;
        }
        
        newPtr->next = l1? l1:l2;
        return newHead->next;
    }
};