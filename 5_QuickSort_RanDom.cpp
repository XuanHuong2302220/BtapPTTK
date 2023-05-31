#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int getRandomPivot(int left, int right) {
    srand(time(NULL));
    return left + rand() % (right - left + 1);
}

int partition(int arr[], int left, int right) {
    int pivotIndex = getRandomPivot(left, right);
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 3, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    int randomPivot = getRandomPivot(0, size - 1);
    cout << "Random pivot: " << randomPivot << endl;

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}

