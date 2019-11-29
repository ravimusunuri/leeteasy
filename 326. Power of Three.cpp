class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        int max = (int) pow(3, 19);
        if ((max % n) == 0) {
            return true;
        } else {
            return false;
        }
    }
};
