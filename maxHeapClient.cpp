//=========================================================
//HW#: HW1P1 max Heap
//Your name: Dragan Lukic
//Complier:  g++
//File type: .cpp file
//===========================================================

#include <iostream>
#include "maxHeap.h"

using namespace std;

int main()
{


    MaxHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    cout << h.getMax() << endl;
    h.removeAt(2);
    cout << h.getMax() << endl;
    cout << h.extractMax() << " ";
    cout << h.getMax() << endl;
	
   int a[7] = {2, 3, 4, 5, 6, 7, 1};
    MaxHeap h2(7);
    h2.heapify(a, 7);
    cout << h2.extractMax() << " ";
    cout << h2.getMax() << " " << endl;
    return 0;
}
