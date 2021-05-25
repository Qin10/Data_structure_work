#include<iostream>
using namespace std;

template<typename T>
class QuadHeap {
private:
    T* array;
    int size;
    int capacity;
public:
    QuadHeap(int capacity);
    ~QuadHeap();
    void insert(T element);
    T deleteMin();
    bool isEmpty();
    void show();
};
template<typename T>
QuadHeap<T>::QuadHeap(int capacity) {
    this->capacity = capacity;
    array = new T[capacity];
    size = 0;
}

template<typename T>
QuadHeap<T>::~QuadHeap() {
    delete[] array;
}

template<typename T>
void QuadHeap<T>::insert(T element) {
    if (size == capacity) {
        throw "The quadHeap is full!";
    }
    if (size == 0) {
        array[0] = element;
        size++;
        return;
    }
    int curIndex = size++;
    while (1) {

        int parentIndex = (curIndex - 1) / 4;

        if (element < array[parentIndex]) {
            array[curIndex] = array[parentIndex];
        }
        else {
            array[curIndex] = element;
            return;
        }

        curIndex = parentIndex;
        if (curIndex == 0) {
            array[curIndex] = element;
            return;
        }
    }
}

template<typename T>
T QuadHeap<T>::deleteMin() {
    if (size == 0) {
        throw "The quadHeap is empty!";
    }
    T elem = array[0];
    T data = array[--size];
    int parentIndex, childIndex;
    for (parentIndex = 0; parentIndex * 4 + 1 < size; parentIndex = childIndex) {
        childIndex = parentIndex * 4 + 1;
        int limit = childIndex + 4;
        for (int i = childIndex + 1; i < size && i < limit; i++) {
            if (array[i] < array[childIndex]) childIndex = i;
        }
        if (data <= array[childIndex]) break;
        array[parentIndex] = array[childIndex];
        parentIndex = childIndex;
    }
    array[parentIndex] = data;
    return elem;

}


template<typename T>
void QuadHeap<T>::show() {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    QuadHeap<int> heap(100);
    try
    {
        cout << "The first insert 10, 12, 1, 14, 6, 5, 8" << endl;
        heap.insert(10);
        heap.insert(12);
        heap.insert(1);
        heap.insert(14);
        heap.insert(6);
        heap.insert(5);
        heap.insert(8);
        cout << "Show: ";
        heap.show();

        cout << "deleteMin()" << endl;
        cout << "The first delete element: " << heap.deleteMin() << endl;
        cout << "The second delete element: " << heap.deleteMin() << endl;
        cout << "Show: ";
        heap.show();

        cout << "The Second insert 15, 3, 9, 7, 4, 11, 13, 2" << endl;
        heap.insert(15);
        heap.insert(3);
        heap.insert(9);
        heap.insert(7);
        heap.insert(4);
        heap.insert(11);
        heap.insert(13);
        heap.insert(2);
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