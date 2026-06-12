#include <iostream>
#include<fstream>
using namespace std;

#define MAX 100
template<typename T>
class Queue {
    public:
    int* arr;
    int maxSize;
    int front, rear;
    int size;
    
    Queue() {
        size = 0;
        maxSize=MAX;
        arr = new int[maxSize];
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear==-1);
    }

    void enqueue(int value) {
        if ((rear+1)%maxSize==front){
            cout<<"Full"<<endl;
            return;
        }
        if (front == -1){
            front =0;
         }
       
        rear=(rear+1)%maxSize;
        arr[rear]=value;
        size++;
    }

    int dequeue() {
        if(front==-1){
            cout<<"Empty"<<endl;
            return -1;
        }
        int temp=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%maxSize;
        }
        size--;
        return temp;
    }
};

class BFSgraph{
    public:
    int size;
    int** graph;
     
     BFSgraph(int size){
        this->size=size;
        graph=new int *[size];

        for(int i=0;i<size;i++){
            graph[i]=new int[size];
        }
     }

int BFS( int* graph[], int start, int end,ofstream& output ) {
    bool* vis= new bool[size];
    for (int i = 0; i < size; i++){
        vis[i] = false;
    }

    int* temp = new int[size];
    for (int i = 0; i < size; i++){
        temp[i] = -1;
    }
    Queue<int> q;
    q.enqueue(start);
    vis[start] = true;

    while (!q.isEmpty()) {
        int node = q.dequeue();

        if (node == end) {
            break;
        }

        for (int i = 0; i < size; i++) {
            if (graph[node][i] == 1 && !vis[i]) {
                q.enqueue(i);
                vis[i] = true;
                temp[i] =node;
            }
        }
    }

    if (temp[end] == -1) {
        return -1;
    }


    int length = 0;
    int curr = end;
    while (curr != start) {
        length++;
        curr = temp[curr];
    }

    output << length <<endl;

    // int* node= new int[length + 1];
    // node[length] = end;

    // curr = end;
    // for (int i = length - 1; i >= 0; i--) {
    //     curr = node[i] = temp[curr];

    // }

    // for (int i = 0; i <=length; i++) {
    //     output << node[i] << " ";
    // }
    // output <<endl;
    // return length;
}
};

int main() {
    ifstream input("in.txt");
    ofstream output("out.txt");
    Queue<int> q;
    int n, m;
    input >> n >> m;
    int** graph = new int* [n];
    for (int i = 0; i < n;i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }
    int u,v;
    for (int i = 0; i < m; i++) {
 
        input >> u >> v;
        graph[u][v] = 1;
    }
    int s, d;
    input>> s >> d;
    BFSgraph g(n);
    int length = g.BFS(graph, s, d,output);
    if (length == -1) {
        output << "-1" <<endl;
    }

    return 0;
}
