class Solution {
public:
    int kthSmallest(const vector<vector<int>> &matrix,const int k){
    	int n = matrix.size();
        if (n == 0)
            return INT_MIN;
        priority_queue<int> pq;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j< n; j++) {
                int val = matrix[i][j];
                
                if (pq.size() < k) {
                    pq.push(val);
                } else if (val < pq.top()) {
                    pq.pop();
                    pq.push(val);
                } else {
                    break;
                }
            }
        }
        return pq.top();
    }
};
