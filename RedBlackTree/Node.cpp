#include "Node.h"

template<class ItemType>
Node<ItemType>::Node(const ItemType & item){
	data=item;
	leftPtr=NULL;
	rightPtr=NULL;
	parentPtr=NULL;
	color="R";
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const{
	return data;
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType & item){
	data=item;
}

template<class ItemType>
Node<ItemType> * Node<ItemType>::getLeftPtr() const{
	return leftPtr;
}

template<class ItemType>
Node<ItemType> * Node<ItemType>::getRightPtr() const{
	return rightPtr;
}

template<class ItemType>
Node<ItemType> * Node<ItemType>::getParentPtr() const{
	return parentPtr;
}

template<class ItemType>
void Node<ItemType>::setLeftPtr(Node<ItemType> * aLeftPtr){
	leftPtr=aLeftPtr;
}

template<class ItemType>
void Node<ItemType>::setRightPtr(Node<ItemType> * aRightPtr){
	rightPtr=aRightPtr;
}

template<class ItemType>
void Node<ItemType>::setParentPtr(Node<ItemType> * aParentPtr){
	parentPtr=aParentPtr;
}

template<class ItemType>
std::string Node<ItemType>::getColor() const{
	return color;
}

template<class ItemType>
void Node<ItemType>::setColor(const std::string aColor){
	color=aColor;
}

template<class ItemType>
void Node<ItemType>::flipColor(){
    if (color == "R") {
        color = "B";
        return;
    }
    color = "R";
}







