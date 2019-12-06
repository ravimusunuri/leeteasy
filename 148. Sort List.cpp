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
    ListNode *sort(ListNode *h){
        if(h==NULL || h->next==NULL){
            return h;
        }
        ListNode *slow = h, *fast = h;
		
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p = slow->next;
        slow->next = NULL;
        ListNode *h1 = sort(h);
        ListNode *h2 = sort(p);
        
        return merge(h1, h2);
        
    }
    
    
    ListNode *merge(ListNode *h1, ListNode *h2){
        
        
        
        ListNode *h = new ListNode(-1) ;
        ListNode *p = h;
        while(h1!=NULL && h2!=NULL){
            if(h1->val < h2->val){
                h->next = h1;
                h1 = h1->next;
            }else{
                h->next = h2;
                h2 = h2->next;
            }
            h = h->next;
        }
        if(h1==NULL){
            h->next = h2;
        }else{
            h->next = h1;
        }
        return p->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        return sort(head);
    }
};
