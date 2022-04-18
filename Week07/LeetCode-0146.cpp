class LRUCache {
    /// We maintain two DSs:
    /// A list to store the values
    /// A hash map to store the keys, where we also store a pointer from the key
    /// to the list node where <key, value> pairs are stored

     // A hash map to store <key, iterator> pairs
    unordered_map<int, list<pair<int, int>>::iterator> keys;
    list<pair<int, int>> values;        // A list to store <key, value> pairs
    int capacity;                       // Cache capacity

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    } // end-LRUCache

    int get(int key) {
        if (keys.count(key) == 0) return -1; // Not found

        // Move the node storing the value to the beginning of the list
        // This is the most recently used key now
        values.splice(values.begin(), values, keys[key]);

        return keys[key]->second;
    } //end-get

    void put(int key, int value) {
        if (keys.count(key) == 0){
            // The key does not exist. Insert it to the front of the list & also to the keys
            // If the capacity is full, then remove the LRU key first
            if (keys.size() == capacity){
                keys.erase(values.rbegin()->first);
                values.pop_back();
            } //end-if

            // Insert the new <key, value> pair at the front of the values list
            values.push_front(make_pair(key, value));
            keys[key] = values.begin();                   // Update the hash map

        } else {
            // Update the value & move the node storing the value to the beginning of the list
            keys[key]->second = value;
            values.splice(values.begin(), values, keys[key]);
        } //end-else
    } //end-put
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */