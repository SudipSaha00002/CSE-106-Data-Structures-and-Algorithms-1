#ifndef LL_H
#define LL_H

#include <iostream>

template <typename T>
class lList {
public:
    T value;
    lList* next;
    lList();
    lList(lList* next, T value=0 );
};


template<typename T>
class LinkedList {
public:
    lList<T>* head;
    lList<T>* tail;
    lList<T>* curr;
    int size;
    int currpos = -1;

    bool isEmpty();
    LinkedList(int size=0 );
    lList<T>* getHead();
    void insert(T value);
    void remove();
    void moveToStart();
    void moveToEnd();
    void next();
    void prev();
    int length();
    void moveToPos(int pos);
    int currPos();
    T getValue();
};

template<typename T>
class Queue {
public:
    LinkedList<T> queue;
    int size;
    Queue();
    void enqueue(T item);
    T dequeue();
    int length();
    T front();
    T back();
    bool is_empty();
    void clear();
    void display();
};

#endif