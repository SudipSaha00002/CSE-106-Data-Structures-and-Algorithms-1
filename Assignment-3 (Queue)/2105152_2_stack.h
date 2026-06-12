#ifndef STACK_H
#define STACK_H
#include"2105152_1_ll_queue.h"
#include"2105152_1_ll_queue.cpp"
// #include"2105152_1_a_queue.h"
// #include"2105152_1_a_queue.cpp"
template<typename E>
class Stack {
public:

    //LinkedList<E> stack;
     Queue<E> stack;


    Stack();
    void clear();
    void push(E item);
    E pop();
    int length();
    E topValue();
    bool isEmpty();
    void StackDisplay();

     std::string DataType();
};

#endif 
