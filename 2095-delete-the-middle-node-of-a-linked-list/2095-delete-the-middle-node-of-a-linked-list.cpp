class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL or head->next == NULL) return NULL;
        
        ListNode *fast = head, *slow = head, *prev = head;
        
        while(fast and fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        prev->next = slow->next;
        slow->next = NULL;
        
        return head;
    }
};