class LRUCache {
    
public:
    int cap;
    unordered_map<int, list<pair<int,int>>::iterator> myMap;
    list<pair<int,int>> myList;
    
    LRUCache(int capacity) {
        cap = capacity;    
    }
    
    int get(int key) {
        auto it = myMap.find(key);
        if (it != myMap.end()) {
            pair<int, int> tmp = *(it->second);
            myList.erase(it->second);
            myMap.erase(key);
            
            myList.push_front({key, tmp.second});
            myMap.insert({key,myList.begin()});
            return tmp.second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = myMap.find(key);
        int sz = myList.size();
        
        if (it != myMap.end()) {
            pair<int, int> tmp = *(it->second);
            myList.erase(it->second);
            myMap.erase(tmp.first);
        } else if ((myList.size() == cap)) {
            auto last = myList.back();
     
            myList.pop_back();
            myMap.erase(last.first);
        }
        
        myList.push_front({key,value});
        myMap.insert({key,myList.begin()});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
