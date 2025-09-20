#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort: O(n^2)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break; // optimization
    }
}

// Selection Sort: O(n^2)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort: O(n^2), good for nearly sorted arrays
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arr2 = arr1;
    vector<int> arr3 = arr1;

    cout << "Original Array: ";
    printArray(arr1);

    bubbleSort(arr1);
    cout << "Bubble Sorted: ";
    printArray(arr1);

    selectionSort(arr2);
    cout << "Selection Sorted: ";
    printArray(arr2);

    insertionSort(arr3);
    cout << "Insertion Sorted: ";
    printArray(arr3);

    return 0;
}
