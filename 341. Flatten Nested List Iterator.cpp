class NestedIterator {
public:
    void compute(NestedInteger val, vector<int> &ans) {
        if (val.isInteger()) {
            ans.push_back(val.getInteger());
        }
        
        else {
            vector<NestedInteger> answ = val.getList();
            for(int i=0;i<answ.size();i++)
                compute(answ[i], ans);
        }
    }
    
    vector<int> ans;
    int pointer = 0;

    NestedIterator(vector<NestedInteger> &myList) {
        for (int i=0; i< myList.size(); i++) {
            compute(myList[i], ans);
        }
    }

    int next() {
        pointer += 1;
        return ans[pointer-1];
    }

    bool hasNext() {
        if (pointer < ans.size())
            return true;
        return false;
    }
};
