class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 1) {
            return false;
        }
        
        int test = 1;
        bool ret = test == num;
        for (int i = 0; i < 31 / 2; ++i) {
            test = test << 2;
            ret |= test == num;
        }
        return ret;
    }
};
