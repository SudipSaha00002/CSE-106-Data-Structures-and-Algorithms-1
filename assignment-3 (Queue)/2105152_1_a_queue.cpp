#include"2105152_1_a_queue.h"
using namespace std;

template<typename T>
arrList<T>::arrList(int K, int X) {
    this->K = K;
    this->X = X;
    arr = new T[K];
    currpos = 0;
}

template<typename T>
void arrList<T>::display() {
    cout << "<";
    for (int i = 0; i < K; i++) {
        cout << arr[i] << " ";
    }
    cout << ">" << endl;
}

template<typename T>
void arrList<T>::insert(T value) {
    if (currpos < 0 || currpos > K) {
        return;
    } else {
        for (int i = K - 1; i >= currpos; i--) {
            arr[i + 1] = arr[i];
        }
        arr[currpos] = value;
        K++;
    }
}

template<typename T>
void arrList<T>::remove() {
    if (currpos < 0 || currpos >= K) {
        return;
    }

    for (int i = currpos; i < K - 1; i++) {
        arr[i] = arr[i + 1];
    }
    K--;
}

template<typename T>
void arrList<T>::moveToStart() {
    currpos = 0;
}

template<typename T>
void arrList<T>::moveToEnd() {
    currpos = K - 1;
}

template<typename T>
void arrList<T>::prev() {
    if (currpos > 0 && currpos <= K) {
        currpos--;
    }
}

template<typename T>
void arrList<T>::next() {
    if (currpos < K - 1) {
        currpos++;
    }
}

template<typename T>
int arrList<T>::length() {
    return K;
}

template<typename T>
int arrList<T>::currPos() {
    return currpos;
}

template<typename T>
void arrList<T>::moveToPos(int pos) {
    currpos = pos;
}

template<typename T>
T arrList<T>::getValue() {
    if (currpos >= 0 && currpos < K) {
        return arr[currpos];
    } else {
        return T();
    }
}

template<typename T>
bool arrList<T>::is_Empty() {
    return (K == 0);
}

template<typename T>
Queue<T>::Queue(int Maxsize) : queue(0, 10), Front(-1), Rear(-1), size(0), Maxsize(Maxsize) {}

template<typename T>
void Queue<T>::enqueue(T item) {
    if ((Rear + 1) % Maxsize == Front) {
        cout << "Full" << endl;
        return;
    }

    if (Front == -1) {
        Front = 0;
    }
    Rear = (Rear + 1) % Maxsize;
    queue.moveToPos(Rear);
    queue.insert(item);
    size++;
}

template<typename T>
T Queue<T>::dequeue() {
    if (Front == -1) {
        cout << "Empty" << endl;
        return T();
    }
    queue.moveToPos(0);
    T n = queue.getValue();
    queue.remove();

    if (Front == Rear) {
        Front = -1;
        Rear = -1;
    } else {
        Front = (Front + 1) % Maxsize;
    }
    size--;
    return n;
}

template<typename T>
int Queue<T>::length() {
    return size;
}

template<typename T>
T Queue<T>::front() {
    if (Front == -1) {
        cout << "Empty" << endl;
    }
    queue.moveToStart();
    return queue.getValue();
}

template<typename T>
T Queue<T>::back() {
    if (Front == -1) {
        cout << "Empty" << endl;
    }
    return queue.arr[Rear];
}

template<typename T>
bool Queue<T>::is_empty() {
    return (Front == -1 && Rear == -1);
}

template<typename T>
void Queue<T>::clear() {
    Front = -1;
    Rear = -1;
    size = 0;
    queue.moveToStart();
    while (!queue.is_Empty()) {
        queue.remove();
    }
}

template<typename T>
void Queue<T>::display() {
    queue.display();
}