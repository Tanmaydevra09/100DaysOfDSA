/*
 Problem: Reverse Pairs (LeetCode 493)

 Time Complexity: O(n log n)
 Space Complexity: O(n) (extra space for merging)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to count reverse pairs during merge
    int merging(vector<int> &arr, int low, int mid, int high)
    {
        int count = 0, j = mid + 1;

        // Count valid reverse pairs before merging
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && arr[i] > 2LL * arr[j])
            {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left++]);
        }
        while (right <= high)
        {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return count;
    }

    // Function to perform merge sort and count reverse pairs
    int mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;
        int count = mergeSort(arr, low, mid) + mergeSort(arr, mid + 1, high) + merging(arr, low, mid, high);

        return count;
    }

    // Main function to count reverse pairs
    int countRevPairs(vector<int> &arr)
    {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 2, 3, 1};

    cout << "Number of Reverse Pairs: " << sol.countRevPairs(arr) << endl;
    return 0;
}
