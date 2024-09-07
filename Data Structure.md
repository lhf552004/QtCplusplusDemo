Overview of Common Data Structures in C++

Here is an introduction to some of the most commonly used data structures in C++:
1. Arrays

    Definition: A collection of elements stored at contiguous memory locations.
    Characteristics: Fixed size, fast access by index.
    Syntax:

    cpp

    int arr[5] = {1, 2, 3, 4, 5}; // Static array

    Use Cases: Useful when the number of elements is known beforehand and does not change.

2. Vectors (std::vector)

    Definition: A dynamic array provided by the STL that can change its size dynamically.
    Characteristics: Supports random access (like arrays) and dynamic resizing.
    Syntax:

    cpp

    #include <vector>
    std::vector<int> v = {1, 2, 3, 4, 5}; // Dynamic array
    v.push_back(6); // Add an element to the end

    Use Cases: When you need a resizable array with fast access by index and want to add or remove elements dynamically.

3. Lists (std::list)

    Definition: A doubly-linked list provided by the STL.
    Characteristics: Fast insertion and deletion from any position, but slower access by index (linear time).
    Syntax:

    cpp

    #include <list>
    std::list<int> l = {1, 2, 3, 4, 5}; 
    l.push_back(6); // Add element at the end
    l.push_front(0); // Add element at the front

    Use Cases: When you need frequent insertions and deletions in the middle of the collection and do not require fast access by index.

4. Deque (std::deque)

    Definition: A double-ended queue that allows insertion and deletion at both ends.
    Characteristics: Fast insertion and deletion from both the front and back, random access (like a vector).
    Syntax:

    cpp

    #include <deque>
    std::deque<int> d = {1, 2, 3};
    d.push_front(0); // Insert at the front
    d.push_back(4); // Insert at the back

    Use Cases: When you need fast insertions/deletions at both ends and random access.

5. Maps (std::map, std::unordered_map)

    Definition:
        std::map: A sorted associative container that stores key-value pairs. Implemented as a self-balancing binary search tree (typically a Red-Black Tree).
        std::unordered_map: An unordered associative container that also stores key-value pairs. Implemented as a hash table.
    Characteristics:
        std::map: Provides logarithmic-time complexity for insertions, deletions, and lookups.
        std::unordered_map: Provides average constant-time complexity (O(1)) for insertions, deletions, and lookups.
    Syntax:

    cpp

    #include <map>
    #include <unordered_map>
    std::map<std::string, int> orderedMap; // Sorted by key
    std::unordered_map<std::string, int> unorderedMap; // Unordered
    orderedMap["apple"] = 1;
    unorderedMap["banana"] = 2;

    Use Cases:
        std::map: When you need to keep the keys sorted.
        std::unordered_map: When you need fast lookups, insertions, and deletions and do not care about the order.

6. Sets (std::set, std::unordered_set)

    Definition:
        std::set: A sorted associative container that stores unique elements.
        std::unordered_set: An unordered associative container that stores unique elements.
    Characteristics:
        std::set: Logarithmic-time complexity for insertions, deletions, and lookups.
        std::unordered_set: Average constant-time complexity (O(1)) for insertions, deletions, and lookups.
    Syntax:

    cpp

    #include <set>
    #include <unordered_set>
    std::set<int> orderedSet = {1, 2, 3}; // Sorted
    std::unordered_set<int> unorderedSet = {1, 2, 3}; // Unordered

    Use Cases:
        std::set: When you need to maintain a sorted collection of unique elements.
        std::unordered_set: When you need fast access and do not care about order.

7. Stack (std::stack)

    Definition: A container adapter that provides LIFO (Last In, First Out) access.
    Characteristics: Allows push, pop, and top operations.
    Syntax:

    cpp

    #include <stack>
    std::stack<int> s;
    s.push(1); // Insert an element at the top
    s.pop(); // Remove the top element

    Use Cases: When you need LIFO access to data, such as in recursive algorithms, expression evaluation, etc.

8. Queue (std::queue)

    Definition: A container adapter that provides FIFO (First In, First Out) access.
    Characteristics: Allows push, pop, and front operations.
    Syntax:

    cpp

    #include <queue>
    std::queue<int> q;
    q.push(1); // Insert an element at the back
    q.pop(); // Remove the front element

    Use Cases: When you need FIFO access to data, such as in breadth-first search (BFS) or task scheduling.

9. Priority Queue (std::priority_queue)

    Definition: A container adapter that provides a way to retrieve the largest (or smallest) element quickly.
    Characteristics: Allows push, pop, and top operations, where top always gives the highest-priority element.
    Syntax:

    cpp

#include <queue>
std::priority_queue<int> pq;
pq.push(1);
pq.push(3);
pq.push(2);
pq.pop(); // Removes the largest element (3)

Use Cases: When you need to maintain a dynamically changing set of elements where you frequently access the largest or smallest element.
