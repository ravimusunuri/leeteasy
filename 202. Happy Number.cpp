class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += ((n%10) *(n%10));
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow, fast;
        slow = fast =n;
        
        do {
            slow = getSum(slow);
            fast = getSum(getSum(fast));
        } while (slow != fast);
            
        return (slow ==1);
        
    }
};
