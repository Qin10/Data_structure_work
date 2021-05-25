#pragma once

template<typename T>
class Node {
private:
	T data;  //存放的数据
	Node* prev;  //上一个节点
	Node* next;  //下一个节点

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