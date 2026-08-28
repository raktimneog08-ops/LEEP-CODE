class PeekingIterator : public Iterator {
private:
    int next_val;
    bool has_next;

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize the cache by reading the first element if available
        has_next = Iterator::hasNext();
        if (has_next) {
            next_val = Iterator::next();
        }
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return next_val;
    }
    
    // Returns the next element in the iteration and advances the iterator.
    int next() {
        int current = next_val;
        has_next = Iterator::hasNext();
        if (has_next) {
            next_val = Iterator::next();
        }
        return current;
    }
    
    // Returns true if the iteration has more elements.
    bool hasNext() const {
        return has_next;
    }
};