#include "divide_et_impera.h"

int max(int arr[], int start, int end) {
    if (start == end) {
        return arr[start];
    } else {
        int mid = (start + end) / 2;
        int left_max = max(arr, start, mid);
        int right_max = max(arr, mid + 1, end);
        return left_max > right_max ? left_max : right_max;
    }
}

int sum(int *arr, int start, int end) {
    if (start == end)
        return arr[start];
    int mid = (start + end) / 2;
    int sum_left = sum(arr, start, mid);
    int sum_right = sum(arr, mid + 1, end);
    return sum_left + sum_right;
}

int binary_search(int arr[], int start, int end, int x) {
    if (start > end) {
        return -1; // az elem nem található a tömbben
    } else {
        int mid = (start + end) / 2;
        if (arr[mid] == x) {
            return mid; // az elem megtalálva
        } else if (arr[mid] > x) {
            return binary_search(arr, start, mid - 1, x); // bal oldali résztömb keresése
        } else {
            return binary_search(arr, mid + 1, end, x); // jobb oldali résztömb keresése
        }
    }
}

void hanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        cout<<"Move disk "<<n<<" from "<<source<<" to "<<dest<<"\n";
    } else {
        hanoi(n - 1, source, aux, dest);
        cout<<"Move disk "<<n<<" from "<<source<<" to "<<dest<<"\n";
        hanoi(n-1, aux, dest, source);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void quickSort(int *array, int low, int high) {
    if (low >= high)
        return;

    int pos = partition(array, low, high);
    quickSort(array, low, pos - 1);
    quickSort(array, pos + 1, high);
}

int partition(int *array, int low, int high) {
    int element = array[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (array[j] < element) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}
