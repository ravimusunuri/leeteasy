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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x=0, y=0, carry=0, sum=0;
        ListNode *head=NULL, **tail=&head;
        
        while (l1!=NULL || l2!=NULL){
           
            sum = carry + getNextVal(l1) + getNextVal(l2);
            
            ListNode *node = new ListNode(sum%10);
            *tail = node;
            tail = (&node->next);
            
            carry = sum/10;
        }
        
        if (carry > 0) { // there is a carry but no more nodes,
            ListNode *node = new ListNode(carry%10);
            *tail = node;
        }
        
        return head;
    }
private:
int getNextVal(ListNode* &l){ // needs to return 0 if null node
        int x = 0;
        if (l != NULL){
            x = l->val;
            l = l->next;
        }
        return x;
    }};
