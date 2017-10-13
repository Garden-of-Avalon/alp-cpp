// Design and implement a data structure for Least Recently Used (LRU) cache. It
// should support the following operations: get and put.
// get(key) - Get the value (will always be positive) of the key if the key
// exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present.
// When the cache reached its capacity, it should invalidate the least recently
// used item before inserting a new item.
// Follow up:
// Could you do both operations in O(1) time complexity?
// Example:
// LRUCache cache = new LRUCache( 2 /* capacity */ );
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

class LRUCache {
  public:
    LRUCache(int capacity) : sz(capacity) {}

    int get(int key) {
        auto iter = cache.find(key);
        if (iter == cache.end())
            return -1;
        touch(iter);
        return iter->second.first;
    }

    void put(int key, int value) {
        auto iter = cache.find(key);
        if (iter != cache.end())
            touch(iter);
        else {
            if (cache.size() == sz) {
                cache.erase(keys.back());
                keys.pop_back();
            }
            keys.push_front(key);
        }
        cache[key] = {value, keys.begin()};
    }

  private:
    int sz;
    // might need change key order frequently, so list is used here
    list<int> keys;
    // to achieve fast erase by value from list
    // use pair record every list node iter and value together
    using valiter = pair<int, list<int>::iterator>;
    // average O(1) access time, choose unordered_map
    unordered_map<int, valiter> cache;

    // actually change key position in the list
    void touch(unordered_map<int, valiter>::iterator iter) {
        keys.erase(iter->second.second);
        keys.push_front(iter->first);
        // now in cache, key keeps same, value keeps same
        // key's position changed to beginning
        iter->second.second = keys.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */