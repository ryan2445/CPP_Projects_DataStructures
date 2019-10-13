#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

void mergeSort(int arr[], int l, int r, int &comparisons, int &swaps);
void merge(int arr[], int l, int m, int r, int &comparisons, int &swaps);
void mergeSortTxtFile(string fileName, int count, int &comparisons, int &swaps);

#endif
