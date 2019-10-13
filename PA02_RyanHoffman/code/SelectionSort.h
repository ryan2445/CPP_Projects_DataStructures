#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

void swap(int *xp, int *yp, int &comparisons, int &swaps);
void selectionSort(int arr[], int n, int &comparisons, int &swaps);
void selectionSortTxtFile(string fileName, int count, int &comparisons, int &swaps);

#endif
