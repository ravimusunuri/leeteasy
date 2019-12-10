class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sum1;
        unordered_map<int, int> sum2;
        int count = 0;
        
        for(int i=0; i< A.size(); i++) {
            for(int j=0; j< B.size();j++) {
                sum1[A[i]+B[j]]++;
            }
        }
        
        for(int i=0; i< C.size(); i++) {
            for(int j=0; j< D.size();j++) {
                sum2[C[i]+D[j]]++;
            }
        }
        
        for (auto it1=sum1.begin(); it1!=sum1.end(); it1++) {
            auto it2 = sum2.find(-it1->first);
            if (it2 != sum2.end()) {
                count += (it1->second * it2->second); 
            }
        }
        return count;
    }
};
