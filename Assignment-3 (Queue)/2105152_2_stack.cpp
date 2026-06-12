#include"2105152_2_stack.h"

using namespace std;


        template<typename E>
        Stack<E>::Stack(){} 
        template<typename E>
        void Stack<E>::clear(){
            stack.clear();
        }
        template<typename E>
        void Stack<E>::push(E item){
            stack.enqueue(item);
        }

        template<typename E>
        E Stack<E>::pop() {
        return stack.dequeue();
        }

        template<typename E>
        int Stack<E>::length(){
            return stack.length();
        }
        template<typename E>
        E Stack<E>::topValue(){
            return stack.back();
        }
        template<typename E>
        bool Stack<E>::isEmpty(){
            if(stack.is_empty()){
                return true;
            }
            return false;  
        }
        template<typename E>
        void Stack<E>::StackDisplay(){
            stack.display();
        }

       template<typename E>
    string Stack<E>::DataType(){
    if(is_same<E,int>::value){
        return "int";
    }
    else if(is_same<E,char>::value){
        return "char";
    }
    else if(is_same<E,double>::value){
        return "double";
    }
}

