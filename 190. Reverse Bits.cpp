class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i=1; i< 32; i++) {
            if(n & 0x1) {
                res = res | 0x1;    
            }
            res = res<<1;
            n = n>>1;
        }
        if(n & 0x1) {
            res = res | 0x1;    
        }
        return res;
    }
};
