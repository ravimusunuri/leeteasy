class Solution {
public:
    double myPow1(double x, int n) {
        
                if (n == 0) 
                return 1;

        if (n == 1) 
                return x;

        double res;

        res = myPow1(x, n/2);
        if ((n%2) == 0) 
                return (res*res);
        else    
                return (x*(res*res));

        
    }
    
    double myPow(double x, int n) {
      double res= myPow1(x, n) ;
      if (n < 0) res = 1/res;
      //if ((x < 0) && (n%2 != 0))
      //    res = -res;
      return res;
    }
};
