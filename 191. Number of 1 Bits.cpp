class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
       for (int i=1; i< 32; i++) {
           if (n & 0x1) {
               count++;
           }
           n = n>>1;
       }
       if (n & 0x1) {
               count++;
        }
        return count;
    }
};
