#include<iostream>
using namespace std;

template<typename T>
class DHeap {
private:
    int d;
    int size;
    int capacity;
    T* elements;
public:
    DHeap(int d, int capacity = 20);
    ~DHeap();
    void insert(T element);
    T delteMin();
    bool isEmpty();
    void show();
};


template<typename T>
DHeap<T>::DHeap(int d, int capacity) {
    this->d = d;
    this->capacity = capacity;
    this->size = 0;
    this->elements = new T[capacity];
}

template<typename T>
DHeap<T>::~DHeap() {
    delete[] elements;
}

template<typename T>
void DHeap<T>::insert(T element) {
    if (size == capacity) {
        throw "The heap is full !";
    }
    if (size == 0) {
        elements[0] = element;
        size++;
        return;
    }
    int curIndex = size++;
    while (1) {

        int parentIndex = (curIndex - 1) / d;

        if (element < elements[parentIndex]) {
            elements[curIndex] = elements[parentIndex];
        }
        else {
            elements[curIndex] = element;
            return;
        }
        curIndex = parentIndex;
        if (curIndex == 0) {
            elements[curIndex] = element;
            return;
        }
    }

}

template<typename T>
void DHeap<T>::show() {
    for (int i = 0; i < size; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}



template<typename T>
T DHeap<T>::delteMin() {
    if (size == 0) {
        throw "The QuadHeap is empty !";
    }
    T elem = elements[0];
    T data = elements[--size];
    int parentIndex, childIndex;
    for (parentIndex = 0; parentIndex * d + 1 < size; parentIndex = childIndex) {
        childIndex = parentIndex * d + 1;
        int limit = childIndex + d;
        for (int i = childIndex + 1; i < size && i < limit; i++) {
            if (elements[i] < elements[childIndex]) childIndex = i;
        }
        if (data <= elements[childIndex]) break;
        elements[parentIndex] = elements[childIndex];
        parentIndex = childIndex;
    }
    elements[parentIndex] = data;
    return elem;
}


template<typename T>
bool DHeap<T>::isEmpty() {
    return (size == 0);
}


int main() {
    DHeap<int> heap(2, 100);
    try
    {

        heap.insert(10);
        heap.insert(12);
        heap.insert(1);
        heap.insert(14);
        heap.insert(6);
        heap.insert(5);
        heap.insert(8);
        cout << "Show: ";
        heap.show();

        cout << "Deleting..." << endl;
        cout << "Delete element: " << heap.delteMin() << endl;
        cout << "Delete element: " << heap.delteMin() << endl;
        cout << "Show: ";
        heap.show();

    }

    catch (const char* msg)
    {
        cerr << msg << '\n';
    }



    system("pause");
    return 0;
}