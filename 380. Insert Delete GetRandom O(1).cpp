class RandomizedSet {
public:
    vector<int> myVec;
    unordered_map<int, int> myMap;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
 
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = myMap.find(val);
        if (it == myMap.end()) {
            myMap.insert({val, myVec.size()});
            myVec.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = myMap.find(val);
        if (it != myMap.end()) {
            int index = it->second;
            myMap.erase(it);
            if ((myVec.size() > 1) && (index != (myVec.size()-1))){
                int last =myVec[myVec.size()-1];
                myVec[index]=last;
                myMap.at(last)=index;
            }
            myVec.pop_back();
            return true;
        }
        return false;
    }
    
