#ifndef BINARY_NODE_
#define BINARY_NODE_
#include <iostream>

template<class ItemType>
class BinaryNode{
private:
	ItemType data;
	BinaryNode<ItemType> *left;
	BinaryNode<ItemType> *right;
public:
	BinaryNode(const ItemType &data);
	ItemType getData();
	BinaryNode<ItemType> *getLeft();
	BinaryNode<ItemType> *getRight();
	void setLeft(BinaryNode<ItemType> *left);
	void setRight(BinaryNode<ItemType> *right);
};

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType &dataItem){
	data=dataItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getData(){
	return data;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeft(){
	return left;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRight(){
	return right;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeft(BinaryNode<ItemType> *leftPtr){
	left=leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRight(BinaryNode<ItemType> *rightPtr){
	right=rightPtr;
}

#endif

