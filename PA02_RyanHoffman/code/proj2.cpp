//RYAN HOFFMAN - CS302 - PROJECT 2
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include "randNumGen.cpp"
#include "SelectionSort.cpp"
#include "MergeSort.cpp"
using namespace std;

int main(){

//--------------UNSORTED TESTS---------------------//
cout << "------------UNSORTED TESTS------------" << endl;
//SELECTION SORT (1,000)
int count=1000;
int comparisons=0;
int swaps=0;
float arr1[10];
float arr2[10];
float arr3[10];
float timeAvg=0;
float comparisonAvg=0;
float swapsAvg=0;
cout << "SELECTION SORT RESULTS (1,000 Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
selectionSortTxtFile(generate(1000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "MERGE SORT RESULTS (1,000 Data Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
mergeSortTxtFile(generate(1000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

count=10000;
timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "SELECTION SORT RESULTS (10,000 Data Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
selectionSortTxtFile(generate(10000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "MERGE SORT RESULTS (10,000 Data Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
mergeSortTxtFile(generate(10000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

count=100000;
timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "SELECTION SORT RESULTS (100,000 Data Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
selectionSortTxtFile(generate(100000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "MERGE SORT RESULTS (100,000 Data Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
mergeSortTxtFile(generate(100000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

cout << "------------SORTED TESTS------------" << endl;

count=1000;
timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "SELECTION SORT RESULTS (1,000 Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
selectionSortTxtFile(generate2(1000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "MERGE SORT RESULTS (1,000 Data Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
mergeSortTxtFile(generate2(1000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

count=10000;
timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "SELECTION SORT RESULTS (10,000 Data Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
selectionSortTxtFile(generate2(10000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "MERGE SORT RESULTS (10,000 Data Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
mergeSortTxtFile(generate2(10000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

count=100000;
timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "SELECTION SORT RESULTS (100,000 Data Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
selectionSortTxtFile(generate2(100000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;

timeAvg=0;
comparisonAvg=0;
swapsAvg=0;
comparisons=0;
swaps=0;
cout << "MERGE SORT RESULTS (100,000 Data Values) (10 Times): " << endl;
for(int i=0;i<10;i++){
auto t1 = std::chrono::high_resolution_clock::now();
mergeSortTxtFile(generate2(100000), count, comparisons, swaps);
auto t2 = std::chrono::high_resolution_clock::now();
arr1[i]=comparisons;
arr2[i]=swaps;
arr3[i]=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}
for(int i=0;i<10;i++){
	timeAvg+=arr3[i];
}
timeAvg/=10;
for(int i=0;i<10;i++){
	comparisonAvg+=arr1[i];
}
comparisonAvg/=10;
for(int i=0;i<10;i++){
	swapsAvg+=arr2[i];
}
swapsAvg/=10;
cout << "Average Time: " << timeAvg << "ms" << endl;
cout << "Average Comparisons: " << comparisonAvg << endl;
cout << "Average Swaps: " << swapsAvg << endl;










return 0;
}
