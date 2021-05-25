#ifndef TASK_2_STACK_STACK_H
#define TASK_2_STACK_STACK_H

#include <iostream>

using namespace std;

class Stack {
private:
    static const int capacity = 10;
    int data[capacity];
    int theSize;

public:
    Stack() // Constructor
    { theSize = 0; }

    // Add a destructor
    ~Stack() {

    };

    void Push(int element) {
        if (theSize == 0) {
            data[0] = element;
            theSize++;
        } else if (theSize < capacity){
            for (int i = 0; i < theSize - 1; i++) {
                data[i + 1] = data[i];
            }
            data[0] = element;
            theSize++;
        } else {
            cout << "The stack is FULL! " <<endl;
        }
    }

    int Pop() {
        if (theSize == 0) {
            cout << "The stack is empty, POP ERROR! " << endl;
            return -1;
        } else {
            int res = data[0];
            for (int i = 0; i < theSize - 1; i++) {
                data[i] = data[i + 1];
            }
            theSize--;
            return res;
        }
    }

    int Peek() {
        if (theSize == 0) {
            cout << "The Stack is EMPTY, PEEK ERROR! " << endl;
            return -1;
        } else {
            return data[0];
        }
    }


    int Size(void) {
        return theSize;
    } // To be implemented

    bool Empty(void)
    { return theSize == 0; }



};


#endif //TASK_2_STACK_STACK_H
