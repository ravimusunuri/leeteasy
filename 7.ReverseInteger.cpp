class Solution {
public:
    int reverse(int x) {
        long rev=0;
        long num = (long) x;
        bool is_neg = false;
        
        if (num < 0) {
            is_neg = true;
            num = -1 * num;
        }
            
        while (num) {
            rev = rev * 10 + (num%10);
            num = (num/10);
        }
        if (rev > INT_MAX) {
            return 0;
        }
        if (is_neg){
            return(-1 * rev);
        }
        return rev;
    }
};
