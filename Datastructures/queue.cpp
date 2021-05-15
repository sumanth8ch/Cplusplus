/* Queue() creates a new queue that is empty. 
enqueue(item) adds a new item to the rear of the queue. 
dequeue() removes the front item from the queue. 
peek() show the front element in the queue.
isEmpty() tests to see whether the queue is empty. 
len() returns the number of items in the queue. */
#include<iostream>
using namespace std;

#define CAPACITY 100

class Queue{
    int a[CAPACITY];
    int front;
    int rear;
    int count;
public:
    Queue(){
        front = 0;
        rear = -1;
        count =0;
    }
    bool isEmpty();
    int len();
    int peek();
    void enqueue(int value);
    void dequeue();
};

int Queue::len(){
    return count;
}

bool Queue::isEmpty(){
    return ((len()) == 0);
}

void Queue::enqueue(int value){
    if (count >= CAPACITY){
        cout<<"overflow\n";
    }
    rear = (rear+1)%CAPACITY;
    a[rear] = value;
    count++;
}

void Queue::dequeue(){
    if (isEmpty()){
        cout<<"queue is empty";
    }
    front = (front+1)%CAPACITY;
    count--;
}

int Queue::peek(){
    if (isEmpty()){
        cout<<"queue is empty";
        return 0;
    }
    return a[front];
}


int main(){
    Queue q;
    q.enqueue(3);
    q.enqueue(8);
    q.enqueue(5);
    q.len();
    cout<<"Element at front is "<<q.peek()<<endl;
    q.dequeue();
    q.len();
}
