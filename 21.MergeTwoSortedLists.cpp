class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* res_start = NULL;
        ListNode* res_end = NULL;
        
        if ((l1 == NULL) && (l2 == NULL)) {
            return NULL;
        }
        
        if (l2 == NULL)
            return l1;
        
        if (l1 == NULL)
            return l2;
        
        while (first || second) {
            if (((first && second) && (first->val < second->val)) || 
                (second == NULL)) {
                if (res_start == NULL){
                    res_start = res_end = first;
                } else {
                    res_end->next = first;
                    res_end = first;
                }
                first = first->next;
            } else {
                if (res_start == NULL){
                    res_start = res_end = second;
                } else {
                    res_end->next = second;
                    res_end = second;
                }
                second=second->next;
             }
        }
         res_end->next =  NULL;
         return res_start;
    }
};
