#include <iostream>
#include "Heap.h"
using namespace std;

int main() {
    int A[] = {222, 5, 76, 54, 111, 33, 875, 74, 736, 454, 444, 23, 2, 1, 1000000, 800070, 6530, 750000, 325100, 100, 770, 999, 43650};
    int n = 23;
    auto heap1 = new Heap(A, n, n*2);
    auto heap2 = new Heap(A, n, n*2);
    //Functions examples:
    heap1->buildMaxHeap(heap1);
    heap2->buildMinHeap(heap2);
    cout << "The heap1: " << endl;
    heap1->printHeap(heap1);
    cout << "The heap2: " << endl;
    heap2->printHeap(heap2);
    cout << "The max of heap1 is: " << heap1->heapMaximum(heap1) << endl;
    cout << "The min of heap2 is: " << heap2->heapMinimum(heap2) << endl;
    cout << "Increasing the value 111 to 654 in heap1 and keeping max heap condition: " << endl;
    heap1->maxHeapIncreaseKey(heap1, 111, 654);
    heap1->printHeap(heap1);
    cout << "Increasing the value 800070 to 654382910 in heap2 and keeping min heap condition: " << endl;
    heap2->minHeapIncreaseKey(heap2, 800070, 654382910);
    heap2->printHeap(heap2);
    cout << "Inserting some new keys inside of heap1 and keeping the max heap condition: " << endl;
    heap1->maxHeapInsert(heap1, 324);
    heap1->maxHeapInsert(heap1, 8789);
    heap1->maxHeapInsert(heap1, 656);
    heap1->printHeap(heap1);
    cout << "Inserting some new keys inside of heap2 and keeping the min heap condition: " << endl;
    heap2->minHeapInsert(heap2, 324);
    heap2->minHeapInsert(heap2, 8789);
    heap2->minHeapInsert(heap2, 656);
    heap2->printHeap(heap2);
}
