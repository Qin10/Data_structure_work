#pragma once

template<typename T>
class Node {
private:
	T data;  //��ŵ�����
	Node* prev;  //��һ���ڵ�
	Node* next;  //��һ���ڵ�

public:
	Node() {
		data = 0;
		next = nullptr;
	}

	Node(T d) {
		data = d;
		next = nullptr;
	}

	~Node() {
		delete next;
	}

	T getData() {
		return data;
	}

	void setData(T d) {
		data = d;
	}

	Node* getNext() {
		return next;
	}

	void setNext(Node* n) {
		next = n;
	}

	Node* getPrev() {
		return prev;
	}

	void setPrev(Node* n) {
		prev = n;
	}
};