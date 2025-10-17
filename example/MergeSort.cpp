#include <iostream>
#include <vector>
using namespace std;

class MergeSort {
public:
    // Function to merge two halves of the array
    // Merges the left and right sub-arrays into a single sorted array
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;  // Size of the left sub-array
        int n2 = right - mid;     // Size of the right sub-array

        vector<int> leftArr(n1), rightArr(n2);  // Temporary arrays to hold the sub-arrays

        // Copy data into temporary arrays
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            rightArr[i] = arr[mid + 1 + i];

        // Merge the temporary arrays back into the original array
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of leftArr, if any
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        // Copy the remaining elements of rightArr, if any
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    // Function to implement merge sort
    void sort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;  // Find the middle point
            sort(arr, left, mid);  // Sort the left half
            sort(arr, mid + 1, right);  // Sort the right half
            merge(arr, left, mid, right);  // Merge the sorted halves
        }
    }

    // Function to print the array
    void printArray(const vector<int>& arr) {
        for (int num : arr) {
            cout << num << " ";  // Print each element
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};  // Sample array
    MergeSort sorter;  // Create an object of MergeSort class

    cout << "Original array: ";
    sorter.printArray(arr);  // Print original array

    sorter.sort(arr, 0, arr.size() - 1);  // Call the sort function to sort the array

    cout << "Sorted array: ";
    sorter.printArray(arr);  // Print the sorted array

    return 0;
}
