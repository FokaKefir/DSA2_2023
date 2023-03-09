#include <iostream>
#include "divide_et_impera.h"

using namespace std;

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[] = {
            4, 6, 2, 9, 4, 6, 1, 2
    };
    int size = 8;
    cout << "Max: " << max(array, 0, size - 1) << "\n";
    cout << "Sum: " << sum(array, 0, size - 1) << "\n";

    int sorted_arr[] = {
            1, 2, 3, 4, 5, 6, 7, 8
    };
    int sorted_size = 8;
    int x = 8;
    cout << "Position of the number " << x << ": " << binary_search(sorted_arr, 0, sorted_size - 1, x) << "\n";

    cout << "Hanoi towers\n";
    hanoi(3, 'A', 'B', 'C');
    cout << endl;

    cout << "Array before sort: ";
    printArray(array, size);
    //mergeSort(array, 0, size - 1);
    quickSort(array, 0, size - 1);
    cout << "Array after sort: ";
    printArray(array, size);

}