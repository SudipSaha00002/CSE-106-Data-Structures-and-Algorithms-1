#include "2105152_1_ll_queue.h"
using namespace std;

        template<typename T>
        lList<T>::lList(){
        value=0;
        next=NULL;
    }
    template<typename T>
    lList<T>::lList(lList* next, T value) {
        this->next = next;
        this->value = value;
    }



        template<typename T>
        bool LinkedList<T>::isEmpty() {
        if (head->next == NULL) {
            return true;
        }
        return false;
    }
    template<typename T>
    LinkedList<T>::LinkedList(int size) {
        this->size = size;
        head = new lList<T>(NULL);
        curr = new lList<T>(NULL);
    }
    template<typename T>
    lList<T>* LinkedList<T>:: getHead() {
        return head;
    }
        template<typename T>
        void LinkedList<T>::insert(T value) { 
        lList<T>* n = new lList<T>;
        n->value = value;
        n->next = NULL;

        if (head == NULL) {
            head = n;
            tail = n;
        } else {
            if (curr == NULL) {
                n->next = head;
                head = n;
            } else {
                n->next = curr->next;
                curr->next = n;
            }
            if (curr == tail) {
                tail = n;
            }
        }
        size++;
        }
    template<typename T>
    void LinkedList<T>::remove() {
        if (curr == NULL )
            return;

        if (curr == head) {
            head = head->next;
            if (head == NULL)
                tail = NULL;
        } else {
            lList<T>* temp = new lList<T>;
            temp=head;
            while (temp != NULL && temp->next != curr) {
                temp = temp->next;
            }
            if (temp != NULL) {
                temp->next = curr->next;
                if (temp->next == NULL)
                    tail = temp;
            }
        }
        delete curr;
        curr = NULL;
        size--;
    }
    template<typename T>
    void LinkedList<T>::moveToStart() {
        curr = head;
    }
    template<typename T>
    void LinkedList<T>::moveToEnd() {
        curr = head;
        if (size == 0) {
            return;
        }
        while (curr->next != NULL && curr->next->next != NULL) {
            curr = curr->next;
        }
    }

     
    template<typename T>
    void LinkedList<T>::next() {
        if (curr->next != NULL) {
            curr = curr->next;
        }
    }

    
    template<typename T>
    void LinkedList<T>::prev() {

        lList<T>* temp =new lList<T>;
        temp= head;
        while (temp != NULL && temp->next != curr) {
            temp = temp->next;
        }
        curr = temp;
    }
    template<typename T>
    int LinkedList<T>::length() {
        return size;
    }
    template<typename T>
    int LinkedList<T>::currPos() {
        int pos = 0;
        lList<T>* temp =new lList<T>;
        temp= head;
        while (temp!=NULL && temp != curr) {
            temp = temp->next;
            pos++;
        }
        return pos;
    }

    template<typename T>
void LinkedList<T>::moveToPos(int pos) {
        if(pos>0 || pos<=size){
        curr = head;
        for(int i=0;i<pos;i++) {
            curr = curr->next;
        }
        }
        else{
            return ;
        }
    
}
    template<typename T>
    T LinkedList<T>::getValue() {
        if(curr->next !=NULL){
        return curr->next->value;
        }
        else{
            return T();
        }
    }

        template<typename T>
       Queue<T>:: Queue(){
            size=0;
        }

        template<typename T>
        void Queue<T>:: enqueue(T item){
            queue.moveToEnd();
            queue.next();
            queue.insert(item);
            size++;
        }
        template<typename T>
        T Queue<T>::dequeue(){
            queue.moveToStart();
            T temp=queue.getValue();
            queue.remove();
            size--;
            return temp;

        }
        template<typename T>
        int Queue<T>::length(){
            return size;
        }
        template<typename T>
        T Queue<T>::front(){
            if(is_empty()){
                return 0;
            }
            queue.moveToStart();
            return queue.getValue();
        }
        template<typename T>
        T Queue<T>:: back(){
            if(is_empty()){
                return 0;
            }
            queue.moveToEnd();
            return queue.getValue();
        }

        template<typename T>
        bool Queue<T>:: is_empty(){
            return queue.length()==0;
        }
        template<typename T>
        void Queue<T>::clear(){
            queue.moveToStart();
            while(size!=0){
                queue.remove();
                queue.moveToEnd();
                size--;
            }
            
        }

        template<typename T>
        void Queue<T>::display(){
            if(queue.length()==0){
                cout<<"< >"<<endl;
                return;
            }
            queue.moveToStart();

            cout<<"< ";
            for(int i=0;i<queue.length();i++){
                cout<<queue.getValue()<<" ";
                queue.next();
            }
            cout<<">"<<endl;
        }



