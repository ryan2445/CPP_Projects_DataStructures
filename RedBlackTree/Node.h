#ifndef NODE_H_
#define NODE_H_
#include <string>

template <class ItemType>
class Node{

private:
ItemType data;
Node<ItemType> * leftPtr;
Node<ItemType> * rightPtr;
Node<ItemType> * parentPtr;
std::string color;

public:
Node(const ItemType & item);
ItemType getItem() const;
void setItem(const ItemType & item);
Node<ItemType> * getLeftPtr() const;
Node<ItemType> * getRightPtr() const;
Node<ItemType> * getParentPtr() const;
void setLeftPtr(Node<ItemType> * aLeftPtr);
void setRightPtr(Node<ItemType> * aRightPtr);
void setParentPtr(Node<ItemType> * aParentPtr);
std::string getColor() const;
void setColor(const std::string aColor);
void flipColor();
};
#endif
