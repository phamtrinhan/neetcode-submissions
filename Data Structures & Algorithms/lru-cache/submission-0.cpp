class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int cap;

    void makeRecent(int key) {
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = prev(order.end());
    }

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }

        makeRecent(key);
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            cache[key].first = value;
            makeRecent(key);
            return;
        }

        if (cache.size() == cap) {
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }

        order.push_back(key);
        cache[key] = {value, prev(order.end())};
    }
};