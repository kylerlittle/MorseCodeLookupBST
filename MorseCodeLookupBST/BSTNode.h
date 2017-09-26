#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

template <class T>
class BSTNode
{
public:
	// Constructor
	BSTNode(T newData) {
		mData = newData;    // overload the assignment operator so that this works for my data
		mpLeft = nullptr;
		mpRight = nullptr;
	}

	// setters
	void setData(const T &newItem) {
		this->mData = newItem;
	}
	void setLeftPtr(const BSTNode<T> *& newLeft) {
		this->mpLeft = newLeft;
	}
	void setRightPtr(const BSTNode<T> *& newRight) {
		this->mpRight = newRight;
	}

	// getters
	T getData() {
		return this->mData;
	}
	BSTNode<T> *& getLeftPtr() {
		return this->mpLeft;
	}
	BSTNode<T> *& getRightPtr() {
		return this->mpRight;
	}

	// destructor
	~BSTNode() {
		// empty destructor because no memory is allocated on the heap
	}

	// print node (will need to overload the '<<' operator to print node correctly)
	void printNode() const {
		cout << this->getData();
	}

private:
	T mData;		// when I instantiate my BST object, I will pass in class Morse type
	BSTNode<T> *mpLeft;
	BSTNode<T> *mpRight;
};