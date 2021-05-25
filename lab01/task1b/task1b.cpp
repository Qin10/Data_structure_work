#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List<int> list;
	list.addFirst(5);
	list.addFirst(4);
	list.addFirst(3);
	list.addFirst(2);
	list.addFirst(1);
	list.addLast(6);
	list.printList();
	cout << endl;
	cout << "remove the first element of the list: " << list.removeFirst() << endl;
	cout << "remove the last element of the list: " << list.removeLast() << endl;
	list.printList();
	cout << endl;
	cout << "The third element is: " << list.returnNth(3) << endl;
	cout << "Whether the list is empty: " << list.isEmpty() << endl;
}
