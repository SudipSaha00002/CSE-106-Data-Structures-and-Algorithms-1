#include<iostream>
using namespace std;
template<typename T>
class arrList {
public:
    T* arr;
    int size;
    int currpos=0;
    int K = 0;
    int X;
    int pos;

    arrList(int K, T X) {
        this->K = K;
        this->X = X;
        arr = new T[K];
    }

    void display() const {
        cout << "<";
        for (int i = 0; i < K; i++) {
                cout << arr[i] << " ";

        }
        cout << ">" << endl;
    }

    void insert(T value) {
        if (currpos < 0 || currpos > K) {
            return;
        }
        else {
            for (int i = K - 1; i >= currpos; i--) {
                arr[i + 1] = arr[i];
            }
            arr[currpos] = value;
            K++;
        }
    }

    void remove() {
        if (currpos < 0 || currpos >= K) {
            return;
        }

        for (int i = currpos; i < K - 1; i++) {
            arr[i] = arr[i + 1];
        }
        K--;
    }

    void moveToStart() {
        currpos = 0;
    }

    void moveToEnd() {
        currpos = K - 1;
    }

    void prev() {
        if (currpos > 0 && currpos <= K) {
            currpos--;
        }
    }

    void next() {
        if (currpos < K - 1) {
            currpos++;
        }
    }

    int length() {
        return K;
    }

    int currPos()  {
        return currpos;
    }

    void moveToPos(int pos) {
            currpos = pos;
    }

    T getValue() {
        if (currpos >= 0 && currpos < K) {
            return arr[currpos];
        }
        else {
            return T();
        }
    }

    bool is_Empty() {
        return (K == 0);
    }
};
