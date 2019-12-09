#ifndef LLRBT_H_
#define LLRBT_H_
#include <algorithm>
#include <memory>
#include <iostream>
#include "Node.cpp"
template<class ItemType>
class LLRBT{

private:
	Node<ItemType> * rootPtr;
	
protected:
	Node<ItemType> * placeNode(Node<ItemType> * subTreePtr, Node<ItemType> * newNode);
 	Node<ItemType> * insertRec(Node<ItemType> * subTreePtr, Node<ItemType> * node);
  Node<ItemType> * deleteRec(Node<ItemType> * subTreePtr, const ItemType & item);
  Node<ItemType> * leftRotate(Node<ItemType> * node);
  Node<ItemType> * rightRotate(Node<ItemType> * node);
  Node<ItemType> * findMin(Node<ItemType> * node);
  Node<ItemType> * deleteMin(Node<ItemType> * node);
  Node<ItemType> * moveRedLeft(Node<ItemType> * node);
  Node<ItemType> * moveRedRight(Node<ItemType> * node);
  Node<ItemType> * fixUp(Node<ItemType> * node);
  bool isRed(Node<ItemType> * node) const;
  void flipColors(Node<ItemType> * node);
  int getHeightFromNode(Node<ItemType> * subTreePtr) const;
	void printPreorder(Node<ItemType> * nodePtr);
public:
	LLRBT();
	int getHeight() const;
	bool add(const ItemType & item);
	void remove(const ItemType & item);
	void preorderCall();
};


#endif

