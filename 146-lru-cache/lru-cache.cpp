class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        auto it = cache[key];          
        int value = it->second;

        cacheList.erase(it);
        cacheList.push_front({key, value});
        cache[key] = cacheList.begin();

        return value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cacheList.erase(cache[key]);
        }

        else if (cache.size() == capacity) {
            int lruKey = cacheList.back().first;
            cacheList.pop_back();
            cache.erase(lruKey);       
        }

        cacheList.push_front({key, value});
        cache[key] = cacheList.begin();
    }

private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> cacheList;   
};