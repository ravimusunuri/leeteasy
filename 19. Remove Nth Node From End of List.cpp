class Solution {
public:
    int remove(ListNode** head, int n) {
        if ((*head) == NULL) {
            return 0;
        }
        
        int ret = remove(&(*head)->next, n);
        if (ret == n) {
            (*head)->next = (*head)->next->next;
        }
        return ret+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ret = remove(&head, n);
        if (ret == n) {
            head = head->next;
        }
        return head;
    }
};
