#include "stack.h"

Stack::Stack()
{

}

void Stack::push(int value)
{
    myList.push_back(value);
}

int Stack::pop()
{
    int lastElement = myList.back();
    myList.pop_back();
    return lastElement;
}

int Stack::top()
{
    int lastElement = myList.back();
    return lastElement;
}

bool Stack::isEmpty()
{
    return myList.size() == 0;
}
