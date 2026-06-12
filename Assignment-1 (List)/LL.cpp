#include<iostream>
using namespace std;

class lList {
    public:
    int value;
    int currpos;
    int size;
    lList* next;
    lList* head;
    lList* tail;
    lList* curr;
    lList* Prev;
    int K;
    lList* availableCars;
    lList* getHead(){
        return head;
    }


    lList() {
        K=0;
        value = 0;
        next = NULL;
        size=0;
        currpos = 0;
        head = NULL;
        tail = NULL;
        curr =  NULL;
    }

    void display() {
        cout << "<";
        curr = head;
        for (int i=0;i<K;i++) {
            if (i==currpos) {
                cout<<"|"<<curr->value<<" ";
            }
            else {
                cout<<curr->value<<" ";
            }
            curr=curr->next;
        }
        cout<<">"<<endl;
    }

    void insert(int value){
        if (currpos<0 || currpos >K){
            return ;
        }

        lList* n=new lList;
        n->value=value;
        n->next=NULL;

        if(head==NULL){
            head=n;
            tail=n;
        }else if(currpos==K){
            tail->next=n;
            tail=n;
        }else if(currpos==0){
            n->next=head;
            head=n;
        }else{
            lList* curr=head;
            for(int i=0;i<currpos-1;i++){
                curr=curr->next;
            }
             n->next=curr->next;
             curr->next=n;
            
        }
        K++;
    }

    void remove() {
        if (currpos < 0 || currpos >=K)
            return;

        lList* temp;
        if (currpos == 0) {
            curr = head;
            head = head->next;
            if (head == NULL)
                tail = NULL;
        } else {
            curr = head;
            for (int i = 0; i < currpos - 1; i++){
                curr = curr->next;
            }
            temp = curr->next;
            curr->next = temp->next;
            if (curr->next == NULL)
                tail = curr;
        }
        K--;
    }

    void moveToStart(){
        currpos=0;
    }

    void moveToEnd(){
        currpos =K-1;
    }

    void prev() {
    if (currpos <= 0 || currpos > K) {
        return;
    }

    if (currpos == 1) {
        curr = head;
        currpos--;
    } else {
        lList* backnode = head;
        for (int i = 0; i < currpos - 2; i++) {
            backnode = backnode->next;
        }
        curr = backnode;
        currpos--;
    }
}

    void Next(){
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
        if(pos>=0 && pos<K)
         currpos=pos;
    }

    int getValue(){
        if(currpos>=0 && currpos< K){
            curr=head;
            for(int i=0;i<currpos;i++){
                curr=curr->next;
            }
        return curr->value;
        }
        return -1;

    }   

};
    

int main(){
    int K;
    cin>>K;
    int value;
    
    lList list;
    list.K=K;
    for(int i=0;i<K;i++){
        cin >> value;
        lList* n=new lList;
        n->value=value;
        n->next=NULL;
        if(i==0){
            list.head=list.tail=list.curr=n;
        }else{
            list.tail->next=n;
            list.tail=n;
        }
    }

    list.display();

    int Q,P;
     while(1){
            cin>>Q;
            switch(Q){
            case 0:
                return 0;
            case 1:
                cin>>P;
                list.insert(P);
                K++;
                list.display();
                cout<<"-1"<<endl;
                break;
            case 2:
                list.remove();
                list.display();
                cout<<"-1"<<endl;
                break;
            case 3:
                list.moveToStart();
                list.display();
                cout<<"-1"<<endl;
                break;
            case 4:
                list.moveToEnd();
                list.display();
                cout<<"-1"<<endl;
                break;
            case 5:
                list.prev();
                list.display();
                cout<<"-1"<<endl;
                break;
            case 6:
                list.Next();
                list.display();
                cout<<"-1"<<endl;
                 break;
            case 7:
                cout<<"Linkedlist length:"<<list.length()<<endl;
                break;
            case 8:
                cout<<"Current position: " <<list.currPos()<<endl;
                break;
            case 9:
                cin>>P;
                list.moveToPos(P);
                list.display();
                cout<<"-1"<<endl;
                break;
            case 10:
                cout<<"Value:"<<list.getValue()<<endl;
                break;
        }
     }
    
    return 0;
}

