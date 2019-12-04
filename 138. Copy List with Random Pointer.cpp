class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p1 = head;
        Node* p2 = NULL;
        Node* res_start = NULL;
        Node* res_end = NULL;
        while (p1 != NULL) {
            Node* tmp= new Node(p1->val);
            p2 = p1->next;
            p1->next = tmp;
            tmp->next = p2;
            p1 = p2;
        }
    
        p1 = head;
        
        while (p1 != NULL) {
            p1->next->random = (p1->random) ? p1->random->next: p1->random;
            p1 = p1->next ? p1->next->next: p1->next;
        }
        
        p1 = head;
        res_start = res_end= p1->next;
        while (p1 && res_end) {
            p1->next = p1->next ? p1->next->next : p1->next;
            res_end->next = res_end->next ?  res_end->next->next: res_end->next;
            p1 = p1->next;
            res_end = res_end->next; 
            
        }
   
        return res_start;
    }
};
