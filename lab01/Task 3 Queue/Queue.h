#ifndef TASK_3_QUEUE_QUEUE_H
#define TASK_3_QUEUE_QUEUE_H
#include <iostream>

using namespace std;

template<typename T>
class Queue {
private:
    int size;
    static const int CAPACITY = 10;
    T queue[CAPACITY];
    int front;
    int back;
public:
    Queue() {
        size = 0;
        front = 0;
        back = -1;
    }

    ~Queue() {

    }

    void enqueue(T element) {
        if (size < CAPACITY) {
            back = (back + 1) % CAPACITY;
            queue[back] = element;
            size++;
        } else {
            cout << "enqueue ERROR£º queue is FULL! " << endl;
        }

    }

    void dequeue() {
        if (size > 0) {
            front = (front + 1) % CAPACITY;
            size--;
        } else {
            cout << "dequeue ERROR! " <<endl;
        }

    }

    bool isEmpty() {
        return size == 0;
    }

    void print() {
        for (int i = front; i < back + 1; i++) {
            cout << queue[i] << ", ";
        }
    }
};


#endif //TASK_3_QUEUE_QUEUE_H
