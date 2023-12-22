#ifndef HEAP_STRUCTURE_TEST_HEAP_H
#define HEAP_STRUCTURE_TEST_HEAP_H

#include <iostream>
#include <string>

class Heap {
public:
    Heap(int* A, int ns, int nl);
    ~Heap();

    int parent(int i) const;
    int left(int i) const;
    int right(int i) const;

    void maxHeapify(Heap* A, int i);
    void buildMaxHeap(Heap* A);
    int heapMaximum(Heap* A);

    void minHeapify(Heap* A, int i);
    void buildMinHeap(Heap* A);
    int heapMinimum(Heap* A);

    //Sort Algorithm
    void heapSort(Heap* A);

    //Operations for priority queues
    int maxHeapExtractMax(Heap* A);
    void maxHeapIncreaseKey(Heap* A, int value, int key);
    void maxHeapInsert(Heap* A, int value);

    int minHeapExtractMin(Heap* A);
    void minHeapIncreaseKey(Heap* A, int value, int key);
    void minHeapInsert(Heap* A, int value);

    //Useful Operations
    void printHeap(Heap* A);

    int getHeapElement(int i);

    int getHeapSize() const;

    void setHeapSize(int heapSize);

    int getHeapLength() const;

    void setHeapLength(int heapLength);

private:
    int* heapElements;
    int heapSize; //Elements inside the heap
    int heapLength; //Total of numbers inside the Array
};
#endif //HEAP_STRUCTURE_TEST_HEAP_H
