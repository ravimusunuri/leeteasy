class Solution {
public:
    int getSum(int a, int b) {
    int s = a ^ b; 
    int carry = a & b; 
  
    if (carry == 0) return s; 
    else return getSum(s, (unsigned int)carry << 1); 
    }
};
