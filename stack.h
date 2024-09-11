#ifndef STACK_H
#define STACK_H
#include <list>

class Stack
{
private:
    std::list<int> myList;
public:
    Stack();
    void push(int value);
    int pop();
    int top();
    bool isEmpty();
};

#endif // STACK_H
