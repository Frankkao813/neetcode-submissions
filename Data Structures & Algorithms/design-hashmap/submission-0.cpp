class MyHashMap {
    vector<int> keys;
    vector<int> values;
public:
    MyHashMap() {

    }

    int _search(int key){
        for (int i = 0; i < keys.size(); i++){
            if (keys[i] == key) return i;
        }

        return -1;
    }
    
    void put(int key, int value) {
        // first search if the 
        int ind = _search(key);
        if (ind == -1){
            keys.push_back(key);
            values.push_back(value);
        }
        else {
            values[ind] = value;
        }
    }
    
    int get(int key) {
        int ind = _search(key);
        if (ind != -1) return values[ind];
        return -1;
    }
    
    void remove(int key) {
        int ind = _search(key);
        if (ind != -1){
            keys.erase(keys.begin() + ind);
            values.erase(values.begin() + ind);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */