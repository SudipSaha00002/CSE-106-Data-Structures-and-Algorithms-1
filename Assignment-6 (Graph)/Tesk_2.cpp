#include <iostream>
#include<fstream>
using namespace std;

template<typename T>
class Stack {
    public:
    int* arr;
    int top;
    int size;
    
    Stack(int size) {
        this->size=size;
        arr = new int[size];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (size-top>1){
            top++;
            arr[top]=value;
        }
        else{
            return ;
        }
    }

    int pop() {
        if(top>=0){
            top--;
            return arr[top+1];
        }
        else{
            return -1;
        }
    }
};
    template<typename T>
    class DFSgraph{
        public:
        int size;
        int** graph;

        DFSgraph(int size){
        this->size=size;
        graph=new int *[size];

        for(int i=0;i<size;i++){
            graph[i]=new int[size];
        }
        }
    

    int  DFS(int* graph[],  int start, int end, bool vis[],Stack<T>& stack) {
    if (start==end) {
        stack.push(start);
    }
     vis[start] = true;
    for (int i = 0; i < size;i++) {
        if (graph[start][i] == 1 && !vis[i]) {
            if (DFS(graph, i, end,vis,stack)) {
                stack.push(start);
            }
        }
    }
    return -1;
}
};
int main() {
    ifstream input("in.txt");
    ofstream output("out.txt");
    int n, m;
    input>> n >> m;

    Stack<int> stack(n);
    int** graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }
    int u, v;
    for (int i = 0; i < m; i++) {
        input>> u >> v;
        graph[u][v] = 1;
    }

    bool* vis= new bool[n];
    for (int i = 0; i < n; i++){
        vis[i] = false;
    }
    DFSgraph<int> g(n);
   int s, d;
    input >> s >> d;
    if (g.DFS(graph,s,d,vis,stack)) {
        output << stack.top <<endl;
        while (!stack.isEmpty()) {
            output<< stack.pop() << " ";
        }
    }
    // } else {
    //     output<< "-1" <<endl;
    // }

    return 0;
}
