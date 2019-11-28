class Solution {
public:
    int mySqrt(int x) {
        
        if (x == 0)
            return 0;
        
        if (x < 4) {
            return 1;
        }
        
        int num;
        long low = 1;
        long high = x;
        long mid;        
        while (low <= high) {
            mid = (low+high)/2;
            if ( (mid * mid) == x) {
                return mid;
            } else if ( (mid * mid) > x) {
                high = mid-1;
            } else {
                num = mid;
                low = mid+1;
            }
        }
        return num;
    }
};
