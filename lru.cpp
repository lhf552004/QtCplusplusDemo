#include "lru.h"


int LRU::get(int key)
{
    if (cache.find(key) == cache.end()) {

        return -1;
    }

    list.splice(list.begin(), list, cache[key]);
    // value of map is key-pair iterator
    return cache[key]->second;
}

void LRU::put(int key, int value)
{
    if (cache.find(key) != cache.end()) {
        // The key is already existed.
        cache[key]->second = value;
        list.splice(list.begin(), list, cache[key]);
        return;
    }
    // Now add new key
    if(cache.size() == capacity) {
        // It is full
        int lru_key = list.back().first;
        list.pop_back();
        cache.erase(lru_key);
    }

    list.push_front(std::make_pair(key, value));
    cache[key] = list.begin();
}
