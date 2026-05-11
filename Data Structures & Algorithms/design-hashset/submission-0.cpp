class MyHashSet {
private:
    vector<int> myHash;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        // Make sure that the method doesn't push in repetitive element
        if (not contains(key)){
            myHash.push_back(key);   
        }
    }
    
    void remove(int key) {
        // Check if the iterator returns the last element
        auto it = find(myHash.begin(), myHash.end(), key);
        if (it != myHash.end()){
            myHash.erase(it);
        }
    }
    
    bool contains(int key) {
        // count method finds the occurence of key in list
        int cnt = count(myHash.begin(), myHash.end(), key);
        if (cnt > 0){
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */