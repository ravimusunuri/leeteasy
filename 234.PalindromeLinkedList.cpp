class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode *temp = head;
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int front = 0, back = v.size() - 1;
        bool isPal = true;
        while(front < back) {
            if(v[front] != v[back]) {
                isPal = false;
                break;
            }
            else {
                front++;
                back--;
            }
        }
        return isPal;        
    }
};
