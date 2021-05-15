/*The stack operations are given below:
Stack(): creates a new stack that is empty.
push(item) : adds a new item to the top of the stack. 
pop() : removes the top item from the stack.
peek() : returns the top item from the stack but does not remove it. 
isEmpty() : tests to see whether the stack is empty.
len() : returns the length of the stack.*/

#include<iostream>
using namespace std;
#define STACKSIZE 1000

class Stack{
    int topindex;
public:
    int a[STACKSIZE];
    Stack(){topindex = -1;}
    bool push(int value);
    int pop();
    int peek();
    int length();
    bool isEmpty();
    int len();
};

int Stack::len(){
    int x = topindex+1;
    return x;
}

bool Stack::isEmpty(){
    return topindex <0;
}

bool Stack::push(int value){
    if (topindex>= STACKSIZE-1){
        cout<< "Stack size limit reached";
        return false;
    }
    else {
        a[++topindex] = value;
        return true;
    }
}

int Stack::pop(){
    if (topindex < 0) {
            cout<<"Stack is empty";
            return 0;}
    else{
        int x = a[topindex--];
        return x;
    }
}

int Stack::peek(){
    if (topindex<0){
        return 0;
    }
    else{int val = a[topindex];
        return val;}
}



int main(){
    class Stack s;
    s.push(3);
    s.push(6);
    s.push(2);
    s.push(89);
    cout<<"The length is "<<s.len()<<"\n";
    cout<< s.pop() << " popped out\n";
    cout<<s.peek();
    return 0;
}
