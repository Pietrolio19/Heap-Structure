#include "Heap.h"
#include <cmath>
#include <exception>
using namespace std;

Heap::Heap(int* A, int ns, int nl) {
    heapElements = new int[nl];
    heapLength = nl;
    heapSize = ns;
    if(heapLength < heapSize)
        throw invalid_argument("The heap size cannot exceed the heap length!");
    if(heapSize != 0)
        for(int i = 0; i < heapSize; i++)
            heapElements[i] = A[i];
    else
        cout << "Nothing as been created" << endl;
}

Heap::~Heap() {
    delete[] heapElements;
}

int Heap::parent(int i) const {
    if(i == 0)
        return 0;
    else
        if(i%2 == 0)
            return (i/2)-1;
        else
            return floor(i/2);
}

int Heap::left(int i) const {
    return 2*i+1; //Array starts from 0
}

int Heap::right(int i) const {
    return 2*i+2; //Same as left
}

//Without this function the if statement in the max and min heapify doesn't work, don't know why...
bool check(int i, int l, int r){
    if(i != l && i != r)
        return false;
    return true;

}

//Function to create specifics Heaps
void Heap::maxHeapify(Heap *A, int i) {
    int largest;
    int l = left(i);
    int r = right(i);
    if(l < A->heapSize && A->heapElements[l] > A->heapElements[i])
        largest = l;
    else
        largest = i;
    if(r < A->heapSize && A->heapElements[r] > A->heapElements[largest])
        largest = r;
    if(check(largest, l, r)) {
        int tmp = A->heapElements[i];
        A->heapElements[i] = A->heapElements[largest];
        A->heapElements[largest] = tmp;
        maxHeapify(A, largest);
    }
}

void Heap::buildMaxHeap(Heap* A) {
    for(int i = floor(A->heapSize/2); i >= 0 ; i--)
        maxHeapify(A, i);
}

int Heap::heapMaximum(Heap *A) {
    return A->heapElements[0];
}

void Heap::minHeapify(Heap *A, int i) {
    int smallest;
    int l = left(i);
    int r = right(i);
    if(l < A->heapSize && A->heapElements[l] < A->heapElements[i])
        smallest = l;
    else
        smallest = i;
    if(r < A->heapSize && A->heapElements[r] < A->heapElements[smallest])
        smallest = r;
    if(check(smallest, l, r)){
        int tmp = A->heapElements[i];
        A->heapElements[i] = A->heapElements[smallest];
        A->heapElements[smallest] = tmp;
        minHeapify(A, smallest);
    }

}

void Heap::buildMinHeap(Heap *A) {
    for(int i = floor(A->heapSize/2); i >= 0 ; i--)
        minHeapify(A, i);
}

int Heap::heapMinimum(Heap *A) {
    return A->heapElements[0];
}

void Heap::heapSort(Heap *A) { //TODO fix heapSort
    A->buildMaxHeap(A);
    for(int i = A->heapSize-1; i>=2; i--){
        int tmp = A->heapElements[0];
        A->heapElements[0] = A->heapElements[i];
        A->heapElements[i] = tmp;
        maxHeapify(A, 0);
    }
}

int Heap::maxHeapExtractMax(Heap *A) {
    int max = A->heapMaximum(A);
    A->heapElements[0] = A->heapElements[A->heapSize-1];
    A->heapSize = A->heapSize - 1;
    A->maxHeapify(A, 0);
    return max;
}

void Heap::maxHeapIncreaseKey(Heap *A, int value, int key) {
    int i = 0;
    while(i < A->heapSize && A->heapElements[i] != value)
        i++;
    if(i == A->heapSize)
        cout << "The value " << value << " doesn't exist" << endl;
    else {
        if (A->heapElements[i] > key)
            cout << "The key " << key << " is smaller than the value" << endl;
        else {
            A->heapElements[i] = key;
            while(i > 1 && A->heapElements[parent(i)] < A->heapElements[i]) {
                int tmp = A->heapElements[i];
                A->heapElements[i] = A->heapElements[parent(i)];
                A->heapElements[parent(i)] = tmp;
                i = parent(i);
            }
        }
    }
}

void Heap::maxHeapInsert(Heap *A, int value) {
    if(A->heapSize == A->heapLength)
        throw out_of_range("The heap size cannot exceed the heap length");
    A->heapSize = A->heapSize + 1;
    int v = value;
    value = round_toward_neg_infinity;
    A->heapElements[A->heapSize-1] = value;
    maxHeapIncreaseKey(A,value,v);
}

int Heap::minHeapExtractMin(Heap *A) {
    int min = A->heapMinimum(A);
    A->heapElements[0] = A->heapElements[heapSize-1];
    heapSize = heapSize - 1;
    A->minHeapify(A, 0);
    return min;
}

void Heap::minHeapIncreaseKey(Heap *A, int value, int key) {
    int i = 0;
    while(i < A->heapSize && A->heapElements[i] != value)
        i++;
    if(i == A->heapSize)
        cout << "The value " << value << " doesn't exist" << endl;
    else {
        if (A->heapElements[i] > key)
            cout << "The key " << key << " is smaller than the value" << endl;
        else {
            A->heapElements[i] = key;
            while(i > 1 && A->heapElements[parent(i)] > A->heapElements[i]) {
                int tmp = A->heapElements[i];
                A->heapElements[i] = A->heapElements[parent(i)];
                A->heapElements[parent(i)] = tmp;
                i = parent(i);
            }
        }
    }
}

void Heap::minHeapInsert(Heap *A, int value) {
    if(A->heapSize == A->heapLength)
        throw out_of_range("The heap size cannot exceed the heap length");
    A->heapSize = A->heapSize + 1;
    int v = value;
    value = round_toward_neg_infinity;
    A->heapElements[heapSize-1] = value;
    minHeapIncreaseKey(A, value, v);
}

void Heap::printHeap(Heap *A) {
    for(int i = 0; i < A->heapSize; i++)
        cout << A->heapElements[i] << " ";
    cout << "" << endl;
}

int Heap::getHeapElement(int i) {
    return heapElements[i];
}

int Heap::getHeapSize() const {
    return heapSize;
}

void Heap::setHeapSize(int hS) {
    Heap::heapSize = hS;
}

int Heap::getHeapLength() const {
    return heapLength;
}

void Heap::setHeapLength(int hL) {
    Heap::heapLength = hL;
}
