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
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* res_head =  NULL;
        ListNode* res_tail = NULL;
        ListNode* t1;
        ListNode* t2;
        
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        t1 = l1;
        t2 = l2;
        
        while ( l1 || l2) {
            
            if (((l1 && l2 ) && (l1->val< l2->val)) || 
                (l2 == NULL)){
                if (res_head == NULL) {
                    res_head = res_tail = l1;
                } else {
                    res_tail->next = l1;
                    res_tail = l1;
                }
                l1 = l1->next;
            } else {
                if (res_head == NULL) {
                    res_head = res_tail = l2;
                } else {
                    res_tail->next = l2;
                    res_tail = l2;
                }
                l2 = l2->next;
            }
        }
        res_tail = NULL;
        return res_head;
    }
    
    ListNode* mergeLists(vector<ListNode*>& lists, int lo, int hi) {
        if( lo == hi) {
            return lists[lo];
        }
        
        int mid = (lo+hi)/2;
        ListNode* left = mergeLists(lists, lo, mid);
        ListNode* right = mergeLists(lists, mid+1, hi);
        return (merge (left, right));
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int sz = lists.size();
        if (sz == 0) {
            return NULL;
        }
        if( sz == 1) {
            return lists[0];
        }
        return mergeLists(lists, 0, sz-1);
    }
};
