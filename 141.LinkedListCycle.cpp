class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        if (head == NULL) {
            return false;
        }
        
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            else 
                return false;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
