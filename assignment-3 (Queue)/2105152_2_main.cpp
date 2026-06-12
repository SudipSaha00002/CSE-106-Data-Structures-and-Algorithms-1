#include"2105152_2_stack.h"
#include"2105152_2_stack.cpp"

using namespace std;

int main(){
   
    string Datatype;
    cin>> Datatype;

    if(Datatype=="int"){
        Stack<int>stack;

        int Q,P;
        while(1){
            int temp;
            cin>>Q;
            switch (Q){
                case 0:
                    return 0;
                case 1:
                    stack.clear();
                    stack.StackDisplay();
                    break;
                case 2:
                    cin>>P;
                    stack.push(P);
                    stack.StackDisplay();
                    break;
                case 3:
                    temp=stack.pop();
                    stack.StackDisplay();
                    cout<<temp<<endl;
                    break;
                case 4:
                    stack.length();
                    stack.StackDisplay();
                    cout<<stack.length()<<endl;
                    break;
                case 5:
                    stack.topValue();
                    stack.StackDisplay();
                    cout<<stack.topValue()<<endl;
                    break;
                case 6:
                    stack.StackDisplay();
                    if(stack.isEmpty()){
                        cout<<"true"<<endl;
                    }
                    else{
                        cout<<"false"<<endl;
                    }
                    break;
                default:
                    cout<<"Invalid input"<<endl;
                    break;
            }
        }
    }

    else if(Datatype=="char"){
        Stack<char>stack;

        int Q;
        char P;
        while(1){
            char temp;
            cin>>Q;
            switch (Q){
                case 0:
                    return 0;
                case 1:
                    stack.clear();
                    stack.StackDisplay();
                    break;
                case 2:
                    cin>>P;
                    stack.push(P);
                    stack.StackDisplay();
                    break;
                case 3:
                    temp=stack.pop();
                    stack.StackDisplay();
                    cout<<temp<<endl;
                    break;
                case 4:
                    stack.length();
                    stack.StackDisplay();
                    cout<<stack.length()<<endl;
                    break;
                case 5:
                    stack.topValue();
                    stack.StackDisplay();
                    cout<<stack.topValue()<<endl;
                    break;
                case 6:
                    stack.StackDisplay();
                    if(stack.isEmpty()){
                        cout<<"true"<<endl;
                    }
                    else{
                        cout<<"false"<<endl;
                    }
                    break;
                default:
                    cout<<"Invalid input"<<endl;
                    break;
            }
        }
    }

    else if(Datatype=="double"){
        Stack<double>stack;

        int Q;
        double P;
        while(1){
            double temp;
            cin>>Q;
            switch (Q){
                case 0:
                    return 0;
                case 1:
                    stack.clear();
                    stack.StackDisplay();
                    break;
                case 2:
                    cin>>P;
                    stack.push(P);
                    stack.StackDisplay();
                    break;
                case 3:
                    temp=stack.pop();
                    stack.StackDisplay();
                    cout<<temp<<endl;
                    break;
                case 4:
                    stack.length();
                    stack.StackDisplay();
                    cout<<stack.length()<<endl;
                    break;
                case 5:
                    stack.topValue();
                    stack.StackDisplay();
                    cout<<stack.topValue()<<endl;
                    break;
                case 6:
                    stack.StackDisplay();
                    if(stack.isEmpty()){
                        cout<<"true"<<endl;
                    }
                    else{
                        cout<<"false"<<endl;
                    }
                    break;
                default:
                    cout<<"Invalid input"<<endl;
                    break;
            }
        }
    }
    return 0;
}