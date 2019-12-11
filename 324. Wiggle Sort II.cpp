class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid= n/2;
        nth_element(nums.begin(), nums.begin()+mid, nums.end());
        partition(nums, nums[mid]);
        
        int i = (n%2) ? mid: mid-1;
        int j = n -1;
        vector<int> res(n);
        
        for (int k=0; k<n;k+=2) {
            res[k] = nums[i--];    
        }
                
                
        for (int k=1; k<n;k+=2) {
            res[k] = nums[j--];   
        }
        nums = res;
    }
    
    void partition(vector<int>& nums, int key) {
        int i = 0;
        int j = nums.size()-1;
        int k = 0;
        while (k < j ) {
            
            if(nums[k] < key) {
                swap(nums[i++], nums[k++]);
            } else if (nums[k] > key) {
                swap(nums[k],nums[j--]);
            } else {
                k++;   
            }
        }
        
    }
};
