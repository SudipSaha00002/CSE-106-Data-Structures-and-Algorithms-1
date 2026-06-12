#include"Task_1.cpp"

bool isOperator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

int OperatorPrecedence(char op){
    if(op=='+' || op=='-'){
        return 1;
    }
    else if(op=='*' || op=='/'){
        return 2;
    }
    return 0;
}

double operation(double a,double b,char op){
    switch(op){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    } 
    return 0;
            
}


bool validOp(string& express){
    Stack<char>stack;

    for(int i=0;i<express.length();i++){
        char c =express[i];
        if(c=='('){
            stack.push(c);
        }
        else if(c==')'){
            if(stack.isEmpty() || stack.topvalue() !='('){
                return false;
            }
            stack.pop();
        }
        else if (isOperator(c)){
            if(i==0 || i==express.length()-1 || isOperator(express[i-1]) || isOperator(express[i+1])){
                return false;
            }
        }
    }
    return stack.isEmpty();
}

double evaluate(string& express){
    Stack<double>operand;
    Stack<char>operator1;
    for(int i=0;i<express.length();i++){
        if(express[i]=='(' && (express[i+1]=='+' || express[i+1]=='-')){
            operand.push(0);
        }
        if(express[i]==' '){
            continue;
        }else if(express[i]=='('){
            operator1.push(express[i]);
        }else if(isdigit(express[i])){
            int input=0;
            while(isdigit(express[i]) && i<express.length()){
                input=input*10+(express[i]-'0');
                i++;
            }
            i--;                                       
            operand.push(input);
        }
        else if(express[i]==')'){
            while(!operator1.isEmpty() && operator1.topvalue()!='('){
                double b=operand.pop();
                double a=operand.pop();
                char op=operator1.pop();
                operand.push(operation(a,b,op));
            }
            operator1.pop();
        }else{
            while(!operator1.isEmpty() && OperatorPrecedence(operator1.topvalue())>=OperatorPrecedence(express[i])){
                double b=operand.pop();
                double a=operand.pop();
                char op=operator1.pop();
                operand.push(operation(a,b,op));
            }
            operator1.push(express[i]);
            if((express[i]=='*' || express[i]=='/') && (express[i+1]=='+' || express[i+1]=='-')){
                express[i]='(';
                i--;
            }
        }
        
    }
        while(!operator1.isEmpty()){
            double b=operand.pop();
            double a=operand.pop();
            char op=operator1.pop();
            operand.push(operation(a,b,op));
        }
    return operand.topvalue();
}

int main(){
    string input;
    getline(cin,input);

    if(validOp(input)){
        double result=evaluate(input);
        cout << "Vaild Expresstion"<<endl;
        cout <<"Computed Value:"<<result<<endl;
    }
    else {
        cout <<"Not valid "<<endl;
    }
    
    return 0;
}