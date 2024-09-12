#ifndef LRU_H
#define LRU_H

#include <list>
#include <unordered_map>



class LRU
{
private:
    int capacity;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
    std::list<std::pair<int, int>> list;
public:
    LRU(int cap): capacity(cap){}
    int get(int key);
    void put(int key, int value);
};

#endif // LRU_H
