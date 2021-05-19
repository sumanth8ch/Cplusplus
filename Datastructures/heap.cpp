/*Max heap is implemented.
  For min heap, reverse the heapify function. */
#include <iostream>
#include <vector>
using namespace std;

void swap(int *x, int *y){
    int temp = *y;
    *y = *x;
    *x = temp;
}

void heapify(vector<int> &ar, int i){
    int length = ar.size();
    int largest = i;
    int lc = 2*i+1;
    int rc = 2*i+2;
    if (lc<length && ar[lc]>ar[largest])
        largest = lc;
    if (rc<length && ar[rc]>ar[largest])
        largest = rc;

    if (largest!=i){
        swap(&ar[i],&ar[largest]);
        heapify(ar,largest);
    }
}

void insert(vector<int> &ar, int value){
    int l = ar.size();
    if (l==0){
        ar.push_back(value);
    }
    else{
        ar.push_back(value);
        for(int i = l/2-1;i>=0;i--)
            heapify(ar,i);
    }
}

void removeNode(vector<int> &ar,int value){
    int l = ar.size();
    int i;
    for (i=0;i<l;i++){
        if(value==ar[i])
            break;
    }
    swap(&ar[i],&ar[l-1]);
    ar.pop_back();
    for(int i =l/2-1;i>=0;i--)
        heapify(ar,i);
}

void display(vector<int> &ar){
    for (int i=0; i<ar.size();i++)
        cout<<ar[i]<<' ';
    cout<<"\n";
}

int main(){
    vector<int> heap;
    insert(heap,5);
    insert(heap,8);
    insert(heap,3);
    display(heap);
    removeNode(heap,8);
    display(heap);
}
