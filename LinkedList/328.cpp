// 328. Odd Even Linked List

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
    if(!head || !head->next || !head->next->next) {
        return head;
    }
    
    ListNode* second = head->next;
    ListNode* temp1 = head;
    ListNode* temp2  = head->next;
    while(temp2 && temp2->next) {
        temp1->next = temp2->next;
        temp2->next = temp2->next->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = second;
    return head;
    
    }
};