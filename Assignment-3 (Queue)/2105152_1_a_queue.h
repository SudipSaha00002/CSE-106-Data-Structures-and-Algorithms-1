#ifndef ARR_H
#define ARR_H
#include <iostream>
using namespace std;

template<typename T>
class arrList {
public:
    T* arr;
    int size;
    int currpos;
    int K;
    int X;
    arrList(int K, int X);
    void display();
    void insert(T value);
    void remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length();
    int currPos();
    void moveToPos(int pos);
    T getValue();
    bool is_Empty();
};

template<typename T>
class Queue {
    public:
    arrList<T> queue;
    int Front;
    int Rear;
    int size;
    int Maxsize;
    Queue(int Maxsize = 100);
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