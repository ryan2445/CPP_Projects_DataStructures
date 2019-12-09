//RYAN HOFFMAN - CS302 - PROJECT 5 - LEFT LEANING RED BLACK TREES
#include "LLRBT.cpp"
using namespace std;

int main(){
cout << "*NOTE: LLRBT PRINTS IN PREORDER*" << endl;
LLRBT<int> t1;
srand(time(NULL));
int fourth = 0;
for(int i=0;i<10;i++){
	int dataItem = rand()%100+1;
	if(i==4){
		fourth=dataItem;
	}
	t1.add(dataItem);
	cout << "ADDING: " << dataItem << endl;
	cout << "TREE: ";
	t1.preorderCall();
	cout << endl;
}
cout << "REMOVING 4TH ELEMENT" << endl;
t1.remove(fourth);
cout << "TREE: ";
t1.preorderCall();
cout << endl;
return 0;
}
