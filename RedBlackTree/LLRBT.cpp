#include "LLRBT.h"

template<class ItemType>
Node<ItemType> * LLRBT<ItemType>::placeNode(Node<ItemType> * subTreePtr, Node<ItemType> * newNode){
    Node<ItemType> * tempPtr;
    if (subTreePtr == NULL){
        return newNode;
    }else if(subTreePtr->getItem() > newNode->getItem()){
        tempPtr=placeNode(subTreePtr->getLeftPtr(), newNode);
        subTreePtr->setLeftChildPtr(tempPtr);
    }else{
        tempPtr=placeNode(subTreePtr->getRightPtr(), newNode);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

template<class ItemType>
Node<ItemType> * LLRBT<ItemType>::insertRec(Node<ItemType> * subTreePtr, Node<ItemType> * node){
	  if (subTreePtr == NULL){
        return node;
    }
    if (node->getItem() < subTreePtr->getItem()){
        subTreePtr->setLeftPtr(insertRec(subTreePtr->getLeftPtr(), node));
    }else{
        subTreePtr->setRightPtr(insertRec(subTreePtr->getRightPtr(), node));
    }
    if (isRed(subTreePtr->getRightPtr()) && !isRed(subTreePtr->getLeftPtr())){
        subTreePtr = leftRotate(subTreePtr);
    }
    if (isRed(subTreePtr->getLeftPtr()) && isRed(subTreePtr->getLeftPtr()->getLeftPtr())) {
        subTreePtr = rightRotate(subTreePtr);
    }
    if (isRed(subTreePtr->getLeftPtr()) && isRed(subTreePtr->getRightPtr())){
        flipColors(subTreePtr);
    }
    return subTreePtr;
}

template<class ItemType>
Node<ItemType> * LLRBT<ItemType>::deleteRec(Node<ItemType> * subTreePtr, const ItemType & item){
    if (item < subTreePtr->getItem()){
        if (subTreePtr->getLeftPtr() != NULL){
            if (!isRed(subTreePtr->getLeftPtr()) && !isRed(subTreePtr->getLeftPtr()->getLeftPtr())) {
                subTreePtr = moveRedLeft(subTreePtr);
            }
            subTreePtr->setLeftPtr(deleteRec(subTreePtr->getLeftPtr(), item));
        }
    }else{
        if(isRed(subTreePtr->getLeftPtr())){
            subTreePtr = rightRotate(subTreePtr);
        }

        if(item == subTreePtr->getItem() && subTreePtr->getRightPtr() == NULL){
            delete subTreePtr;
            return NULL;
        }

        if(subTreePtr->getRightPtr() != NULL){
            if(!isRed(subTreePtr->getRightPtr()) && !isRed(subTreePtr->getRightPtr()->getLeftPtr())){
                subTreePtr = moveRedRight(subTreePtr);
            }

            if(item == subTreePtr->getItem()){
                subTreePtr->setItem(findMin(subTreePtr->getRightPtr())->getItem());
                subTreePtr->setRightPtr(deleteMin(subTreePtr->getRightPtr()));
            }else{
                subTreePtr->setRightPtr(deleteRec(subTreePtr->getRightPtr(), item));
            }
        }
    }
    return fixUp(subTreePtr);
}

template<class ItemType>
Node<ItemType> * LLRBT<ItemType>::leftRotate(Node<ItemType> * node){
   	Node<ItemType>* temp = node->getRightPtr();
    node->setRightPtr(temp->getLeftPtr());
    temp->setLeftPtr(node);
    temp->setColor(node->getColor());
    node->setColor("R");
    return temp;
}

template<class ItemType>
Node<ItemType> * LLRBT<ItemType>::rightRotate(Node<ItemType> * node){
   	Node<ItemType>* temp = node->getLeftPtr();
    node->setLeftPtr(temp->getRightPtr());
    temp->setRightPtr(node);
    temp->setColor(node->getColor());
    node->setColor("R");
    return temp;
}

template<class ItemType>
Node<ItemType> * LLRBT<ItemType>::findMin(Node<ItemType> * node){
    while (node->getLeftPtr() != NULL){
        node = node->getLeftPtr();
    }
    return node;
}

template<class ItemType>
Node<ItemType> * LLRBT<ItemType>::deleteMin(Node<ItemType> * node){
    if (node->getLeftPtr() == NULL){
        delete node;
        return NULL;
    }
    if (!isRed(node->getLeftPtr()) && !isRed(node->getLeftPtr()->getLeftPtr())){
        node = moveRedLeft(node);
    }
    node->setLeftPtr(deleteMin(node->getLeftPtr()));
    return fixUp(node);
}

template<class ItemType>
Node<ItemType> * LLRBT<ItemType>::moveRedLeft(Node<ItemType> * node){
	  flipColors(node);
    if (node->getRightPtr() != NULL && isRed(node->getRightPtr()->getLeftPtr())){
        node->setRightPtr(rightRotate(node->getRightPtr()));
        node = leftRotate(node);
        flipColors(node);
    }
    return node;
}

template<class ItemType>
Node<ItemType> * LLRBT<ItemType>::moveRedRight(Node<ItemType> * node){
	  flipColors(node);
    if (node->getLeftPtr() != NULL && isRed(node->getLeftPtr()->getLeftPtr())){
        node = rightRotate(node);
        flipColors(node);
    }
    return node;
}

template<class ItemType>
Node<ItemType> * LLRBT<ItemType>::fixUp(Node<ItemType> * node){
	  if (isRed(node->getRightPtr())){
        node = leftRotate(node);
    }
    if (isRed(node->getLeftPtr()) && isRed(node->getLeftPtr()->getLeftPtr())){
        node = rightRotate(node);
    }
    if (isRed(node->getLeftPtr()) && isRed(node->getRightPtr())){
        flipColors(node);
    }
    return node;
}

template<class ItemType>
bool LLRBT<ItemType>::isRed(Node<ItemType> * node) const{
		if (node != NULL){
				if(node->getColor()=="R"){
					return true;
				}
    }
   return false;
}

template<class ItemType>
void LLRBT<ItemType>::flipColors(Node<ItemType> * node){
    node->flipColor();
    node->getLeftPtr()->flipColor();
    node->getRightPtr()->flipColor();
}

template<class ItemType>
int LLRBT<ItemType>::getHeightFromNode(Node<ItemType> * subTreePtr) const{
    if (subTreePtr == NULL){
        return 0;
    }else{
        int leftHeight = getHeightFromNode(subTreePtr->getLeftPtr());
        int rightHeight = getHeightFromNode(subTreePtr->getRightPtr());
        return std::max(leftHeight, rightHeight) + 1;
    }
}

template<class ItemType>
LLRBT<ItemType>::LLRBT(){
	rootPtr=NULL;
}

template<class ItemType>
int LLRBT<ItemType>::getHeight() const{
	return getHeightFromNode(rootPtr);
}

template<class ItemType>
bool LLRBT<ItemType>::add(const ItemType & item){
    Node<ItemType> * newNodePtr = new Node<ItemType>(item);
    rootPtr = insertRec(rootPtr, newNodePtr);
    rootPtr->setColor("B");
    return true;
}

template<class ItemType>
void LLRBT<ItemType>::remove(const ItemType & item){
	rootPtr = deleteRec(rootPtr, item);
}

template<class ItemType>
void LLRBT<ItemType>::printPreorder(Node<ItemType> * nodePtr){
    if (nodePtr == NULL) {
        return;
    }
    std::cout << nodePtr->getItem() << "[" << nodePtr->getColor() << "] ";
    printPreorder(nodePtr->getLeftPtr());
    printPreorder(nodePtr->getRightPtr());
}

template<class ItemType>
void LLRBT<ItemType>::preorderCall(){
	printPreorder(rootPtr);
}





















