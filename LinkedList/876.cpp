// 876. Middle of the Linked List

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        
        while(temp2) {
            
            temp1 = temp1->next;
            if(temp2->next!=nullptr) {
                temp2 = temp2->next->next;
            }
            else {
                temp2 = nullptr;
            }
        }
        return temp1;
    }
};