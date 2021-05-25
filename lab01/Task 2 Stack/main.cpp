#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack myStack;
    for (int i = 0; i < 10; i++)  {
        myStack.Push(i);
    }
    cout << "The top element is " << myStack.Peek() << endl;
    cout << "Pop an element is " << myStack.Pop() << endl;
    cout << "Now the top element is " << myStack.Peek() <<endl;
    cout << myStack.Empty();
    return 0;
}
