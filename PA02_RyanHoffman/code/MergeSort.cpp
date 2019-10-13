#include <iostream>
#include <fstream>
using namespace std;
#include "MergeSort.h"

void merge(int arr[], int l, int m, int r, int &comparisons, int &swaps){ 
    int i, j, k; 
    int n1 = m-l+1; 
    int n2 = r-m; 
    int L[n1], R[n2]; 
    for (i=0;i<n1;i++){
    		swaps++;
        L[i]=arr[l+i]; 
    }
    for (j=0;j<n2;j++){
    		swaps++;
        R[j] = arr[m+1+j];
    } 
    i = 0; 
    j = 0;
    k = l;
    while (i<n1&&j<n2){ 
        if (L[i] <= R[j]){ 
        		comparisons++;
        		swaps++;
            arr[k] = L[i]; 
            i++; 
        } 
        else{
        		swaps++;
            arr[k]=R[j]; 
            j++; 
        } 
        k++; 
    }
    while(i<n1){
    		swaps++;
        arr[k]=L[i]; 
        i++; 
        k++; 
    } 
    while(j<n2){
    		swaps++;
        arr[k]=R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int arr[], int l, int r, int &comparisons, int &swaps){ 
    if (l<r){ 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m, comparisons, swaps); 
        mergeSort(arr, m+1, r, comparisons, swaps); 
        merge(arr, l, m, r, comparisons, swaps);
    } 
}

void mergeSortTxtFile(string fileName, int count, int &comparisons, int &swaps){
	ifstream read;
	read.open(fileName);
	int arr[count];
	for(int i=0;i<count;i++){
		int temp=0;
		read >> temp;
		arr[i]=temp;
	}
	int n = sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr, 0, n-1, comparisons, swaps);
	ofstream write;
	string fileName2 = "sorted"+fileName;
	write.open(fileName2);
	for(int i=0;i<count;i++){
		write << arr[i] << endl;
	}
}











