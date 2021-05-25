#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template<typename T>
class List {
private:
	Node<T>* head;
	int length;
public:
	List() {
		length = 0;
		head = nullptr;
	}

	virtual ~List() {

	}

	int getLength() {
		return length;
	}

	void addLast(T ele) {
		Node<T>* node = new Node<T>(ele);
		if (head == nullptr) {
			head = node;
			head->setNext(nullptr);
			head->setPrev(nullptr);
		}
		else {
			Node<T>* mid = head;
			for (int i = 0; i < length - 1; i++) {
				mid = mid->getNext();
			}
			mid->setNext(node);
			node->setPrev(mid);
			node->setNext(nullptr);
		}
		length++;
	}

	void addFirst(T ele) {
		Node<T>* node = new Node<T>(ele);
		if (head == nullptr) {
			head = node;
			node->setNext(nullptr);
			node->setPrev(nullptr);
		}
		else {
			node->setNext(head);
			head->setPrev(node);
			head = node;
		}
		length++;
	}

	T removeFirst() {
		if (isEmpty()) {
			cout << "There is no element in the list!" << endl;
			return -1;
		}
		else {
			Node<T>* temp = head;
			head = head->getNext();
			T data = head->getData();
			temp->setNext(nullptr);
			head->setPrev(nullptr);
			delete temp;
			length--;
			return data;
		}
	}

	T removeLast() {
		if (isEmpty()) {
			cout << "There is no element in the list!" << endl;
			return -1;
		}
		else {
			T data;
			Node<T>* tempLast = head;
			Node<T>* tempSecToLast = head;
			//get the last node
			for (int i = 0; i < length - 1; i++) {
				tempLast = tempLast->getNext();
			}
			//get the second to last node
			for (int i = 0; i < length - 2; i++) {
				tempSecToLast = tempSecToLast->getNext();
			}
			data = tempLast->getData();
			tempSecToLast->setNext(nullptr);
			delete tempLast;
			length--;
			return data;
		}
	}

	T returnNth(int nth) {
		if (nth >= 0 && nth <= length) {
			T data;
			Node<T>* temp = head;
			for (int i = 0; i < length - 2; i++) {
				temp = temp->getNext();
			}
			data = temp->getData();
			return data;
		}
		else {
			cout << "Out of range!" << endl;
			return -1;
		}
	}

	void printList() {
		Node<T>* temp = head;
		for (int i = 0; i < length; i++) {
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
	}

	bool isEmpty() {
		return length == 0;
	}
};