/*  LinkedList() creates a new list that is empty.   
    inser(item) adds a new item to the list.
    remove(item) removes the item from the list.
    search(item) searches for the item in the list.
    isEmpty() tests to see whether the list is empty.
    display() prints the list. */

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *nextnode;
};

class LinkedList{
    Node* head;

public:
    LinkedList(){
        head = NULL;
    }
    void insert(int value);
    bool search(int value);
    void remove(int value);
    void display();
    bool isEmpty();
};

bool LinkedList::isEmpty(){
    return(head == NULL);
}

void LinkedList::insert(int value){
    Node* newnode = new Node;
    newnode->data = value;
    newnode->nextnode = NULL;
    if (isEmpty()){
        head =newnode;
    }
    else{
        newnode->nextnode = head;
        head =newnode;
    }
}

bool LinkedList::search(int value){
    Node* x = head;
    while(x!=NULL){
        if (x->data==value){
            return true;
        }
        x = x->nextnode;
    }
    return false;
}

void LinkedList::remove(int value){
    if (head->data==value){
        delete head;
        head = head->nextnode;
        return;
    }
    if (head->nextnode == NULL)
      {
        if (head->data == value)
        {
          delete head;
          head = NULL;
          return ;
        }
        cout << "No value found!" << endl;
        return ;
      }
      Node* x = head;
      while(x->nextnode!= NULL)
      {
        if (x->nextnode->data == value)
        {
          Node* x_ptr = x->nextnode->nextnode;
          delete x->nextnode;
          x->nextnode = x_ptr;
          return ;
        }
        x = x->nextnode;
      }
      cout << "No value found" << endl;
    }
void LinkedList::display(){
    Node* x =head;
    while(x != NULL)
    {
        cout<<x->data<<" ";
        x =x->nextnode;
    }
    cout<<endl;
}

int main(){
    LinkedList l;
    l.insert(14566);
    l.insert(567);
    l.insert(3456);
    l.display();
    l.remove(567);
    l.display();
    cout<<l.search(567);
    return 0;
}
