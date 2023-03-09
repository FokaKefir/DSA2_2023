#ifndef DSA2_DIVIDE_ET_IMPERA_H
#define DSA2_DIVIDE_ET_IMPERA_H

#include <iostream>

using namespace std;

int max(int arr[], int start, int end);
int sum(int arr[], int start, int end);
int binary_search(int arr[], int start, int end, int x);
void hanoi(int n, char source, char dest, char aux);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);

#endif //DSA2_DIVIDE_ET_IMPERA_H
