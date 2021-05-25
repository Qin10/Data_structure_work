#include <iostream>
using namespace std;
/*
This file implements a small part of the class AList.
The purpose of this file is to illustrate
how one can get started on Task 1a on Lab 1.
AList uses an array and handles only integer elements.
(No .h file is needed for this sample code.)
*/
class AList
{
public:
	AList() // Constructor
	{
		theSize = 0;
	}
	// Add a destructor
	~AList() { }
	void AddFirst(int element)
	{
		// This version does nothing if the array is full.
		// Better exception handling is, of course, recommended!
		if (theSize < capacity) {
			for (int i = theSize; i > 0; i--) // Make room for the new first element.
			{
				data[i] = data[i - 1];
			}
		}
		else {
			throw "Exception: The capacity is not enough!";
		}
		data[0] = element; // Add the new element first.
		theSize++;
	}
	void AddLast(int element) {
		if (theSize > 0 && theSize < capacity) {
			theSize++;
			data[theSize - 1] = element; // Add the new element last.
		}
		else {
			throw "Exception: Wrong!";
		}
	} // To be implemented
	int RemoveFirst(void) {
		// Should add exception handling when theSize = 0.
		if (theSize > 0)
		{
			int temp = data[0]; // Get the value of last element, which should be returned
			theSize--; // Decrease the number of elements
			return temp;
		}
		else {
			throw "Exception: There is no element to remove!";
		}
	} // To be implemented
	int RemoveLast(void)
	{
		// Should add exception handling when theSize = 0.
		if (theSize > 0)
		{
			int temp = data[theSize - 1]; // Get the value of last element, which should be returned
			theSize--; // Decrease the number of elements
			return temp;
		}
		else {
			throw "Exception: There is no element to remove!";
		}
	}
	int ReturnNth(int nr) {
		if (nr < theSize) {
			return data[nr];
		}
		else {
			throw "Exception: Wrong position!";
		}
	} // To be implemented
	void PrintList(void) {
		for (int i = 0; i < theSize; i++) {
			cout << data[i];
		}
	} // To be implemented
	int Size(void) {
		return sizeof(data);
	} // To be implemented
	bool Empty(void)
	{
		return theSize == 0;
	}
private:
	static const int capacity = 10;
	int data[capacity];
	int theSize;
};

int main(int argc, char** argv)
{
	// Write some code to test your implementation of AList.
	AList alist;
	try {
		alist.AddFirst(1);
		alist.AddFirst(2);
		alist.AddFirst(3);
		alist.AddFirst(4);
		alist.AddFirst(5);
		alist.PrintList();
		cout << "\nadding the elem at the first pos: " << endl;
		alist.AddFirst(6);
		alist.PrintList();
		cout << "\nadding the elem at the last pos: " << endl;
		alist.AddLast(0);
		alist.PrintList();
		cout << "\nprinting the elem at the 3 pos: " << endl;
		int n_value = alist.ReturnNth(-3);
		cout << "3 position: " << n_value << endl;
		cout << "removing the first and the last elem: " << endl;
		alist.RemoveLast();
		alist.RemoveFirst();
		alist.PrintList();
	}
	catch (char* e) {
		cout << e << endl;
	}
	catch (...) {
		cout << "Wrong" << endl;
	}

	return 0;
}