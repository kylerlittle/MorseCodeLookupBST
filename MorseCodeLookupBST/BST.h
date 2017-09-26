#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BSTNode.h"
#include "Morse.h"

using std::string;
using std::cin;
using std::cout;
using std::fstream;

template <class T>
class BST
{
public:
	// Constructor
	// Description: we are not allowing the user to modify the tree once it is created;
	//				this function reads input from the file, allocates memory on the heap
	//				for each new object in thre tree, & inserts the new nodes into the tree
	//				using my insert function
	BST(fstream &input) {
		mpRoot = nullptr;   // initially an empty binary search tree

		while (!input.eof()) {  // continue reading in from file while not at the end
			T newItem;  // declare item of object T to read into
			input >> newItem;   // read in from file; store into object of class T
			insert(newItem);	// insert item into tree
		}
	}

	// Public Destructor
	~BST() {
		destruct(mpRoot);
	}

	// isEmpty()
	bool isEmpty() {
		bool result = false;
		if (this->mpRoot == nullptr) {
			result = true;
		}
		return result;
	}

	// public insert function
	void insert(T &newItem) {
		insert(newItem, mpRoot);
	}

	// public print binary tree (declare as const)
	void printTree() const {
		printTree(mpRoot);
	}

	// search binary tree (declare as const)
	// Precondition: assumes the searchValue will, in fact, be found
	// Description: searches through binary tree until the BSTNode<T> pointer 'found' points
	//				to the value being searched for; returns a copy of the data (NOT a
	//				reference because we don't want the user to modify it)
	T search(T searchValue) const {
		BSTNode<T> *found = mpRoot;
		while (found->getData() != searchValue) {
			if (searchValue < found->getData()) {   // traverse left subtree to find
				found = found->getLeftPtr();
			}
			else {   // traverse right subtree
				found = found->getRightPtr();
			}
		}
		return found->getData();
	}

private:
	BSTNode<T> * mpRoot;

	// insert
	// Preconditions: there are no repeated values; '<' & '>' operators are overloaded for 
	//				 whatever data type 'T' is.
	// Description: this function privately inserts a new node into the binary search tree
	//				via recursion. Once the recursed pointer is null, we have found the
	//				position to insert. The function allocates space on the heap & sets
	//				the nullptr to point at the newly allocated memory (filled with newItem).
	void insert(T &newItem, BSTNode<T> *& pRoot) {
		if (pRoot == nullptr) {		// found spot to insert
			pRoot = new BSTNode<T>(newItem); // allocate space on the heap for node
		}
		else if (newItem < pRoot->getData()) {  // newItem should go down left subtree
			insert(newItem, pRoot->getLeftPtr());
		}
		else {	// newItem should go down right subtree
			insert(newItem, pRoot->getRightPtr());
		}
	}

	// delete
	// Description: follows post-order transversal so that the root node is destroyed last
	void destruct(BSTNode<T> *& pTree) {
		if (pTree != nullptr) {   // once it equals null, recursive step will end (base case)
			destruct(pTree->getLeftPtr());
			destruct(pTree->getRightPtr());
			cout << "Node to be deleted:" << pTree->getData();
			delete pTree;
		}
	}

	// Description: follows in-order traversal so that the nodes are printed in order
	//				(i.e. starting with the lower ASCII values first!)
	//				Note that parameter pTree is not a reference since I do not
	//				need to modify the pointers; in fact, I want to avoid that.
	void printTree(BSTNode<T> *pTree) const {
		if (pTree != nullptr) {  // base case -- recursion ends once leaf nodes are reached
			printTree(pTree->getLeftPtr());
			cout << pTree->getData();
			printTree(pTree->getRightPtr());
		}
	}
};