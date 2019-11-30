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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL) {
            return head;
        }
        
        ListNode *odd_start = NULL, *odd_end=NULL;
        ListNode *even_start = NULL, *even_end = NULL;
        ListNode *p1 = head;
        bool is_odd = true;
        while (p1 != NULL) {
            if (is_odd) {
                if (odd_start== NULL) {
                    odd_start = odd_end = p1;
                } else {
                    odd_end->next = p1;
                    odd_end = odd_end->next;
                }
                is_odd = false;
            } else {
                 if (even_start== NULL) {
                    even_start = even_end = p1;
                } else {
                    even_end->next = p1;
                    even_end = even_end->next;
                }
                is_odd = true;
            }
            p1 = p1->next;
        }
        ListNode* res;
        res = odd_start;
        odd_end->next = even_start;
        if(even_end) {
            even_end->next = NULL;
        }
        return res;
    }
};
