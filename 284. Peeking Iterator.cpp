class PeekingIterator : public Iterator {
public:
    bool saved;
	int num;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        saved=false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!saved) {
            num = Iterator::next();
            saved = true;
        }
        return num;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(saved) {
            saved = false;
            return num;
        } else {
            return Iterator::next();
        }
	}

	bool hasNext() const {
	    return saved || Iterator::hasNext();
	}
};
