#include "StackLinked.h"
#include "Stack.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber){
	top=NULL;
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other){
	StackNode * curr=top;
	StackNode * orig=other.top;
		while(orig!=NULL){
			curr=new StackNode(orig->dataItem, orig->next);
			if(!top){
				top=curr;
			}
			orig=orig->next;
			curr=curr->next;
		}
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other){
	StackNode * curr=top;
	StackNode * orig=other.top;
		while(orig!=NULL){
			curr=new StackNode(orig->dataItem, orig->next);
			if(!top){
				top=curr;
			}
			orig=orig->next;
			curr=curr->next;
		}
	return *this;
}

template <typename DataType>
StackLinked<DataType>::~StackLinked(){
	clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error){
	if(isFull()){
		throw logic_error("Error1: The stack is full.");
	}
	top=new StackNode(newDataItem, top);
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error){
	if(isEmpty()){
		throw logic_error("Error2: The stack is empty.");
	}
	StackNode * curr=top;
	DataType item = curr->dataItem;
	curr=curr->next;
	top=curr;
	return item;
}

template <typename DataType>
void StackLinked<DataType>::clear(){
	StackNode * curr=top;
	StackNode * prev=NULL;
	while(curr!=NULL){
		prev=curr;
		curr=curr->next;
		delete prev;
	}
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const{
	if(top==NULL){
		return true;
	}
	return false;
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const{
	return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const{
	if(isEmpty()){
		cout << "Error3: Stack is empty." << endl;
	}
	else{
		StackNode * curr=top;
		while(curr!=NULL){
			cout << curr->dataItem;
			curr = curr->next;
		}
	}
}

template<typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType &nodeData, StackNode *nextPtr):dataItem(nodeData), next(nextPtr) {
}






