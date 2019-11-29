class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        
         if (size1 == 0) {
             int mid = size2/2;
             if ((size2 % 2) == 0) {
                 return ( nums2[mid] + nums2[mid-1])/2.0;
             } else {
                 return nums2[mid];
             }
         }
        if (size2 == 0) {
             int mid = size1/2;
             if ((size1 % 2) == 0) {
                 
                 return ( nums1[mid] + nums1[mid-1])/2.0;
             } else {
                 return nums1[mid];
             }
         }
        
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0;
        int high = size1;
        double med = 0.0;
        int x, leftx, lefty, rightx, righty;
        int y;
        while (low <= high) {
            x = (low+high)/2;
            y = ((size1+size2+1)/2) -x;
                
            leftx = ((x == 0) ? INT_MIN: nums1[x-1]);
            rightx = ((x == size1) ? INT_MAX: nums1[x]); 
            
            lefty = ((y == 0) ? INT_MIN: nums2[y-1]);
            righty = ((y == size2) ? INT_MAX: nums2[y]); 
            
            if (leftx > righty) {
                high = x - 1;
            } else if (lefty > rightx) {
                low= x + 1;
            } else {
                if (((size1+size2) % 2) == 0){
                    med = (max (leftx, lefty) + min(rightx, righty))/2.0; 
                  } else {
                    med = max(leftx, lefty);
                }
                break;
            }
        }
        
        return med;
    }
};
