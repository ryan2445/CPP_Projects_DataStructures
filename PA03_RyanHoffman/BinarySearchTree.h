#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryNode.h"
#include <iostream>
using namespace std;

template<class ItemType>
class BinarySearchTree{
private:
BinaryNode<ItemType> * rootPtr;
protected:

public:
	BinarySearchTree();
	bool add(const ItemType & newData);
	BinaryNode<ItemType>* placeNode(BinaryNode<ItemType> * subPtr, BinaryNode<ItemType> * newPtr);
	int getHeight(BinaryNode<ItemType> * nodePtr);
	void printPreorder(BinaryNode<ItemType> * nodePtr);
	void preorderCall();
	void printPostorder(BinaryNode<ItemType> * nodePtr);
	void postorderCall();
	void printInorder(BinaryNode<ItemType> * nodePtr);
	void inorderCall();
	void printHeight();
};

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(){
	rootPtr=NULL;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType & newData){
	BinaryNode<ItemType> *newPtr = new BinaryNode<ItemType>(newData);
	rootPtr=placeNode(rootPtr, newPtr);
	return true;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType> *subPtr, BinaryNode<ItemType> *newPtr){
	BinaryNode<ItemType> *tempPtr;
	if(subPtr==NULL){
		return newPtr;
	}
	else if(subPtr->getData() > newPtr->getData()){
		tempPtr=placeNode(subPtr->getLeft(), newPtr);
		subPtr->setLeft(tempPtr);
	}
	else{
		tempPtr=placeNode(subPtr->getRight(), newPtr);
		subPtr->setRight(tempPtr);
	}
	return subPtr;
}

template <class ItemType>
void BinarySearchTree<ItemType>::printPreorder(BinaryNode<ItemType> * nodePtr){
	if(nodePtr==NULL){
		return;
	}
	cout << nodePtr->getData() << " ";
	printPreorder(nodePtr->getLeft());
	printPreorder(nodePtr->getRight());
}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderCall(){
	printPreorder(rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::printPostorder(BinaryNode<ItemType> * nodePtr){
	if(nodePtr==NULL){
		return;
	}
	printPostorder(nodePtr->getLeft());
	printPostorder(nodePtr->getRight());
	cout << nodePtr->getData() << " ";
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderCall(){
	printPostorder(rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::printInorder(BinaryNode<ItemType> * nodePtr){
	if(nodePtr==NULL){
		return;
	}
	printInorder(nodePtr->getLeft());
	cout << nodePtr->getData() << " ";
	printInorder(nodePtr->getRight());
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderCall(){
	printInorder(rootPtr);
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight(BinaryNode<ItemType> * nodePtr){
	if(nodePtr==NULL){
		return 0;
	}
	else{
		int lHeight=getHeight(nodePtr->getLeft());
		int rHeight=getHeight(nodePtr->getRight());
		if(lHeight > rHeight){
			return (lHeight+1);
		}
		else{
			return (rHeight+1);
		}
	}
	return 0;
}

template <class ItemType>
void BinarySearchTree<ItemType>::printHeight(){
	cout << getHeight(rootPtr);
}






















#endif
