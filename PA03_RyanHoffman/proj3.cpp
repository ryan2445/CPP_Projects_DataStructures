#include <iostream>
#include <cstdlib>
using namespace std;
#include "BinarySearchTree.h"

int main(){

BinarySearchTree<int> b1;
int randInt=0;
for(int i=0;i<10;i++){
	randInt=rand()%200+1;
	b1.add(randInt);
}
cout << "BST Tree Height: ";
b1.printHeight();
cout << endl << "Print Preorder: ";
b1.preorderCall();
cout << endl << "Print Postorder: ";
b1.postorderCall();
cout << endl << "Print Inorder: ";
b1.inorderCall();
cout << endl;
return 0;
}
