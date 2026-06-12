#include<iostream>
#include<string>
#include<cmath>
using namespace std;

template <typename E>

class Stack{

    public:
    int K;
    int X;
    int top;
    E* listArray;

    Stack(){
        K=1;
        top=-1;
        listArray=new E[K];
    }

    ~Stack(){
        delete [] listArray;
    }

    void display(){
        cout << "<";
        for (int i = 0; i<=top; i++) {
            cout << listArray[i]<<" ";
        }
        cout << ">" <<endl;
    }

    void clear(){
        top=-1;
    }

    void push(const E& item){
    if(top == K - 1){
        K = K * 2;
        E* arr = new E[K];
        for(int i = 0; i <= top; i++){
            arr[i] = listArray[i];
        }
        delete[] listArray;
        listArray = arr;
    }
    top++;
    listArray[top] = item;
}

    E pop(){
        if(top>-1){
            top--;
            return listArray[top+1];
        }

        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return listArray[top+1];
    }


    int length(){
        return (top+1);
    }

     E topvalue(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
        return E();
        }
        return listArray[top];
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

string Datatype(){
    if(is_same<E,int>::value){
        return "int";
    }
    else if(is_same<E,char>::value){
        return "char";
    }
}

};

// int  main(){

//     string Datatype;
//     cin>> Datatype;

//     int K,X;
//     cin>>K>>X;

//     if(Datatype=="int"){
//         Stack<int>stack;
//         for(int i=0;i<K;i++){
//             int item;
//             cin>>item;
//            stack.push(item);
//         }
    
//         stack.display();

//         int Q,P;
//         while(1){
//             cin>>Q;
//             switch (Q){
//                 case 0:
//                     return 0;
//                     break;
//                 case 1:
//                     stack.clear();
//                     stack.display();
//                     break;
//                 case 2:
//                     cin>>P;
//                     stack.push(P);
//                     stack.display();
//                     break;
//                 case 3:
//                      stack.pop();
//                     stack.display();
//                     break;
//                 case 4:
//                     stack.display();
//                     cout<<"Length of the stack:"<<stack.length()<<endl;
//                     break;
//                 case 5:
//                     stack.display();
//                     cout<<"Top value:"<<stack.topvalue()<<endl;
//                     break;
//                 case 6:
//                     stack.display();
//                     if(stack.isEmpty()){
//                         cout<<"true"<<endl;
//                     }
//                     else{
//                         cout<<"false"<<endl;
//                     }
//                     break;
//                 default:
//                     cout<<"Invalid input"<<endl;
//                     break;
//             }
//         }
//     }

//     else if(Datatype=="char"){
//         Stack<char>stack;
//         for(int i=0;i<K;i++){
//             char item;
//             cin>>item;
//             stack.push(item);
//         }

//         stack.display();

//         int Q;
//         char P;
//         while(1){
//             cin>>Q;
//             switch (Q){
//                 case 0:
//                     return 0;
//                     break;
//                 case 1:
//                     stack.clear();
//                     stack.display();
//                     break;
//                 case 2:
//                     cin>>P;
//                     stack.push(P);
//                     stack.display();
//                     break;
//                 case 3:
//                     stack.pop();
//                     stack.display();
//                     break;
//                 case 4:
//                     stack.display();
//                     cout<<"Length of the stack:"<<stack.length()<<endl;
//                     break;
//                 case 5:
//                     stack.display();
//                     cout<<"Top value:"<<stack.topvalue()<<endl;
//                     break;
//                 case 6:
//                     stack.display();
//                     if(stack.isEmpty()){
//                         cout<<"true"<<endl;
//                     }
//                     else{
//                         cout<<"false"<<endl;
//                     }
//                     break;
//                 default:
//                     cout<<"Invalid input"<<endl;
//                     break;
//             }
//         }
//     }

//     return 0;
// }

