#include"2105152_1_ll_queue.h"
#include"2105152_1_ll_queue.cpp"

// #include"2105152_1_a_queue.h"
// #include"2105152_1_a_queue.cpp"
int main(){
    Queue<int> queue;

    while(1){
    int temp;
    int Q;
    int P;
        cin>>Q;
        switch(Q){
            case 0:
                return 0;
            case 1:
                cin>>P;
                queue.enqueue(P);
                queue.display();
                break;
            case 2:
                temp=queue.dequeue();
                queue.display();
                cout<<temp<<endl;
                break;
            case 3:
                queue.display();
                cout<<queue.length()<<endl;
                break;
            case 4:
                queue.display();
                cout<<queue.front()<<endl;
                break;
            case 5:
                queue.display();
                cout<<queue.back()<<endl;
                break;
            case 6:
                queue.display();
                if(queue.is_empty()){
                    cout<<"True"<<endl;
                }else{
                    cout<<"False"<<endl;
                }
                break;
            case 7:
                queue.clear();
                queue.display();
                break;
            default:
                cout<<"Invalid"<<endl;
        }

    }

    return 0;
}