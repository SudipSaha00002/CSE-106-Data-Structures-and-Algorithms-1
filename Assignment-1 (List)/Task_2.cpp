#include"arr.cpp"
//#include"LL.cpp"
int main(){
    int K,X;
    cin>>K>>X;
    arrList Arr(K,X);
    for(int i=0;i<K;i++){
        cin>>Arr.arr[i];
    }

    int Q,P;
    cin>>Q;

    while(1){
        switch(Q){
        case 0:
                return 0;
                break;    
        case 1: //clear  implementation
                while(Arr.length()>0){
                    Arr.remove();
                }
                    Arr.display();
                    cout<<"-1"<<endl;
                    break;
        case 2: //Apend implementation
                cin>>P;
                Arr.moveToEnd();
                Arr.insert(P);
                Arr.display();
                cout<<"-1"<<endl;
                break; 
        case 3: //search implementation
                cin>>P;
                for(int i=0;i<Arr.length();i++){
                    if(Arr.arr[i]==P){
                        cout<<"1"<<endl;
                    }
                    else if(Arr.arr[i]!=P){
                        cout<<"-1"<<endl;
                    }
                }           
                break;
     
        }
    }
}