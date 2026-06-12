#include <iostream>
#include<fstream>
using namespace std;

#define MAX 100
template <typename T>
class MaxPriorityQueue {
public:
    T* arr;
    int maxSize;
    int Size;
    
MaxPriorityQueue()  {
    Size=0;  
    maxSize=MAX;                   
    arr = new T[maxSize];
}

void MaxHeapify(int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if (left <= Size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= Size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        MaxHeapify(largest);
    }
}

void Insert(T x) {
    if (Size == maxSize) {
        maxSize=maxSize*2;
        T * arr=new T[maxSize];    
    }
    int i =++Size;
    while (i > 1 && x > arr[i / 2]) {
        arr[i] = arr[i / 2];
        i = i / 2;
    }
    arr[i] = x;
}

T FindMax() {
    if (Size > 1) {
        return arr[1];
    }
    else{
        return -1;
    }
}

T ExtractMax() {
    if(Size>1){
    T max = arr[1];
    arr[1] = arr[Size--];
    MaxHeapify(1);
    return max;
    }
    else {
        return -1;
    }
}

void IncreaseKey(int i, T newKey) {
    if (newKey > arr[i]) {
    arr[i] = newKey;
    while (i > 1 && arr[i] > arr[i / 2]) {
    swap(arr[i], arr[i / 2]);
    i = i / 2;
    }
    }
    return;
}

void DecreaseKey(int i, T newKey) {
    if (newKey <arr[i]){
    arr[i] = newKey;
    MaxHeapify(i);
    }
    return;
}

void Print(ostream& output){
    output << "No of elements: " << Size <<endl;
    int row = 1;
    int count = 0;
    for (int i = 1; i <= Size; i++) {
        output << arr[i] << "\t";
        count++;
        if (count == row) {
            output <<endl;
            row *= 2;
            count = 0;
        }
    }
    output << endl;
}

void Sort() {
    for (int i =Size/2; i >= 1; i--) {
        MaxHeapify(i);
    }
    int n =Size;
    for (int i = Size; i >= 2;i--) {
        swap(arr[1], arr[i]);
        Size--;
        MaxHeapify(1);
    }
    Size = n;
}

T index(int i){
    if (i > 1 || i <= Size) {
     return arr[i];
    }
    else{
        return -1;
    }
}

};

int main() {
    ifstream input("input.txt"); 
    ofstream output("output.txt");

    MaxPriorityQueue<int> Queue;
    int n;

    while ( input >> n) {

        switch (n) {
            case 1: {
                int value;
                input >> value;
                Queue.Insert(value);
                break;
            }
            case 2: {
                int max =Queue.FindMax();
                output << "Max: " << max << endl;
                break;
            }
            case 3: {
                int max = Queue.ExtractMax();
                output << "Max: " <<max<<" has been extracted." << endl;
                break;
            }
            case 4: {
                int i, newKey;
                input >> i >> newKey; 

                if (newKey >Queue.index(i)) {
                    Queue.IncreaseKey(i, newKey);
                    output << "Key increased!" << endl;
                } else {
                    output << "New key is not larger than the previous key" << endl;
                }
                break;
            }
            case 5: {
                int i, newKey;
                input >> i >> newKey;
                if (newKey < Queue.index(i)) {
                    Queue.DecreaseKey(i, newKey);
                    output << "Key decreased!" << endl;
                } else {
                    output << "New key is not smaller than the previous key" << endl;
                }
                break;
            }
            case 6: {
                Queue.Print(output);
                break;
            }
            case 7: {
                Queue.Sort();
                Queue.Print(output);
                break;
            }
            default:
                output << "Invalid" << endl;
        }
    }
    return 0;
}


