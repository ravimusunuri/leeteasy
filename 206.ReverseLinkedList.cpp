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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre, *cur, *lat;
        if (head == NULL) {
            return NULL;
        }
        pre = NULL;
        cur = head;
        
        while (cur) {
            lat = cur->next;
            cur->next = pre;
            pre = cur;
            cur = lat;
        }
        return pre;
        
    }
};
