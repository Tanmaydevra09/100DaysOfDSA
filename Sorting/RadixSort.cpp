// RadixSort.cpp
// Day 25 of 100DaysOfDSA
// Implementation of Radix Sort Algorithm

#include <iostream>
#include <vector>
using namespace std;

// Get maximum value in arr
int getMax(const vector<int>& arr) {
    int mx = arr[0];
    for (int x : arr)
        if (x > mx) mx = x;
    return mx;
}

// Counting sort used as a subroutine in radix sort
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it contains actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main radix sort function
void radixSort(vector<int>& arr) {
    int m = getMax(arr);

    // Do counting sort for every digit
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Unsorted array: ";
    printArray(arr);

    radixSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
