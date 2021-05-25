#include <iostream>
#include "Queue.h"

using namespace std;
int main() {
    Queue<int> q;
    cout << myqueue.isEmpty();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    cout << endl;
    q.dequeue();
    q.print();
    cout<< endl;
    cout << q.isEmpty();
    return 0;
}
