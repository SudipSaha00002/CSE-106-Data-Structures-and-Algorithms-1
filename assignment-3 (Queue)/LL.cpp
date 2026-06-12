#include <iostream>
using namespace std;

template <typename T>
class lList {
public:
    T value;
    lList* next;

    lList(){
        value=0;
        next=NULL;
    }

    lList(lList* next, T value=0) {
        this->next = next;
        this->value = value;
    }
};

template <typename T>
class LinkedList {
public:
    lList<T>* head;
    lList<T>* curr;
    lList<T>* tail;
    int size;
    int currpos=-1;

    bool isEmpty() {
        if (head->next == NULL) {
            return true;
        }
        return false;
    }

    LinkedList(int size = 0) {
        this->size = size;
        head = new lList<T>(NULL);
        curr = new lList<T>(NULL);
    }

    lList<T>* getHead() {
        return head;
    }

        void insert(T value) { 
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

    void remove() {
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

    void moveToStart() {
        curr = head;
    }

    void moveToEnd() {
        curr = head;
        if (size == 0) {
            return;
        }
        while (curr->next != NULL && curr->next->next != NULL) {
            curr = curr->next;
        }
    }

     

    void next() {
        if (curr->next != NULL) {
            curr = curr->next;
        }
    }

    

    void prev() {

        lList<T>* temp =new lList<T>;
        temp= head;
        while (temp != NULL && temp->next != curr) {
            temp = temp->next;
        }
        curr = temp;
    }

    int length() {
        return size;
    }

    int currPos() {
        int pos = 0;
        lList<T>* temp =new lList<T>;
        temp= head;
        while (temp!=NULL && temp != curr) {
            temp = temp->next;
            pos++;
        }
        return pos;
    }

    void moveToPos(int pos) {
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

    T getValue() {
        if(curr->next !=NULL){
        return curr->next->value;
        }
        else{
            return T();
        }
    }

};

