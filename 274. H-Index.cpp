class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hIndex = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) 
            if ((i + 1) <= citations[i]) 
                xhIndex = i + 1;
        return hIndex;
    }
};
