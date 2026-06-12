
#include<iostream>
using namespace std;

class arrList{
    public:
    int *arr;
    int size;
    int currpos;
    int K=0,X;
    int pos;
    
    
    arrList(int K,int X){
        this->K=K;
        this->X=X;
        arr=new int[K];
        
    } 

    void display(){
        cout<<"<";
        for(int i=0;i<K;i++){
            if(i==currpos){
                cout<<"|"<<arr[i]<<" ";
            }
            else{
                cout<<arr[i]<<" ";
            }
            
        }
        cout<<">"<<endl;
    }

    void insert(int value){
        if(currpos<0 || currpos>K){
            return ;
        }
        else{
            for(int i=K-1;i>=currpos;i--){
                arr[i+1]=arr[i];
            }
            arr[currpos]=value;
            K++;
        }
    }

    void remove(){
       if(currpos<0 || currpos>K){
            return ;
        }
        
        for(int i=currpos;i<K-1;i++){
            arr[i]=arr[i+1];
        }
        K--;
    }


    void moveToStart(){
        currpos=0;
    }

    void moveToEnd(){
        currpos=K-1;
    }

    void prev(){
        if(currpos>0 || currpos<=K){
            currpos--;
        }
    }

    void next(){
        if(currpos<K-1){
            currpos++;
        }
    }


    int length(){
        return K;
    }


    int currPos(){
        return currpos;
    }


    void moveToPos(int pos){
         if(pos>0 && pos<K){
            currpos=pos;
         }
        
    }


    int getValue(){
         if(currpos>=0 && currpos<K){
            return arr[currpos];
         }
         else{
            return -1;
         }
    }

};


// int main(){
//     int K,X;
//     cin>>K>>X;

//     arrList Arr(K,X);
//      for(int i=0;i<Arr.K;i++){
//         cin>>Arr.arr[i];
//      }

//      Arr.display();
//     int Q,P;
//     while (1){
//     cin>>Q;

    
//     switch(Q){
//         case 0:
//             return 0;
//         case 1:
//             cin>>P;
//             Arr.insert(P);
//             Arr.display();
//             cout<<"-1"<<endl;
//             break;
//         case 2:
//             Arr.remove();
//             Arr.display();
//             cout<<"-1"<<endl;
//             break;
//         case 3:
//             Arr.moveToStart();
//             Arr.display();
//             cout<<"-1"<<endl;
//             break;
//         case 4:
//             Arr.moveToEnd();
//             Arr.display();
//             cout<<"-1"<<endl;
//             break;
//         case 5:
//             Arr.prev();
//             Arr.display();
//             cout<<"-1"<<endl;
//             break;
//         case 6:
//             Arr.next();
//             Arr.display();
//             cout<<"-1"<<endl;
//             break;
//         case 7:
//             cout<<"Array length:"<<Arr.length()<<endl;
//             break;
//         case 8:
//             cout<<"Current position: " <<Arr.currPos()<<endl;
//             break;
//         case 9:
//             cin>>P;
//             Arr.moveToPos(P);
//             Arr.display();
//             cout<<"-1"<<endl;
//             break;
//         case 10:
//             cout<<"Value:"<<Arr.getValue()<<endl;
//             break;    
//      }
//     }

//     return 0;
// }