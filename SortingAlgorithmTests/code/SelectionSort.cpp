#include <iostream>
#include <fstream>
using namespace std;
#include "SelectionSort.h"

void swap(int *a, int *b, int &comparisons, int &swaps){
	swaps++;
	int temp = *a;  
  *a = *b;  
  *b = temp;
}

void selectionSort(int arr[], int n, int &comparisons, int &swaps){  
    int i, j, min;  
    for (i = 0; i < n-1; i++){
        min = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min]){
        		comparisons++;
            min = j;
        }
        swap(&arr[min], &arr[i], comparisons, swaps);
    
    }
}

void selectionSortTxtFile(string fileName, int count, int &comparisons, int &swaps){
	ifstream read;
	read.open(fileName);
	int arr[count];
	for(int i=0;i<count;i++){
		int temp=0;
		read >> temp;
		arr[i]=temp;
	}
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n, comparisons, swaps);
	ofstream write;
	string fileName2 = "sorted"+fileName;
	write.open(fileName2);
	for(int i=0;i<count;i++){
		write << arr[i] << endl;
	}
}
