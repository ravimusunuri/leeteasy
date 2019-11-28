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
    int length(ListNode* node) {
        if (node == NULL) {
            return 0;
        }
        return(1+length(node->next));
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a_len = length (headA);
        int b_len = length (headB);
        
        if ((a_len == 0) && (b_len == 0)) {
            return NULL;
        } 
        
        if ((a_len == 0) || (b_len == 0)) {
            return NULL;
        }
        
        ListNode* ptr_a = headA;
        ListNode* ptr_b = headB;
        int min_count;
        if (a_len > b_len) {
            int count = a_len - b_len;
            while (count > 0) {
                ptr_a = ptr_a->next;
                count--;
            }
            min_count = b_len;
        } else {
             int count = b_len - a_len;
            while (count > 0) {
                ptr_b = ptr_b->next;
                count--;
            }
            min_count = a_len;
        }
        
        while (min_count > 0) {
            
            if (ptr_a == ptr_b)
              return ptr_a;
            
            ptr_a = ptr_a->next;
            ptr_b = ptr_b->next;
            min_count--;
        }
       
        return NULL;
    }
};
