//RYAN HOFFMAN - CS302 - ASSIGNMENT 4 - HEAPS USING STL
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
void printVector(vector<int> & v1);
int main(){
	int mean=0;
	srand(time(NULL));
	vector<int> v1;
	
	for(int i=0;i<100;i++){
		int randNum=rand()%10;
		v1.push_back(randNum);
	}
	cout << "INITIAL VECTOR WITH RANDOM VALUES: " << endl;
	printVector(v1);
	cout << endl;
	
	make_heap(v1.begin(), v1.end());
	cout << "NEW HEAP: " << endl;
	printVector(v1);
	
	for(int i=0;i<v1.size();i++){
		mean+=v1.at(i);
	}
	mean/=v1.size();
	v1.push_back(mean);
	push_heap(v1.begin(), v1.end());
	cout << endl << "MEAN OF HEAP: " << mean;
	cout << endl << "HEAP AFTER ADDING MEAN: " << endl;
	printVector(v1);
	
	pop_heap(v1.begin(), v1.end());
	v1.pop_back();
	cout << endl << "HEAP AFTER DELETING MAXIMUM ELEMENT: " << endl;
	printVector(v1);
	
	sort_heap(v1.begin(), v1.end());
	cout << endl << "HEAP AFTER SORTING: " << endl;
	printVector(v1);
	cout << endl;
	
	return 0;
}

void printVector(vector<int> & v1){
	for(int i=0;i<v1.size();i++){
		cout << v1.at(i) << " ";
	}
}
