#include <iostream>
#include <vector>
using namespace std;

class QuickSort {
public:
    // Function to partition the array into two parts
    // One part has elements smaller than the pivot, the other part has elements larger than the pivot
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];  // Choose the last element as the pivot
        int i = low - 1;  // Pointer for the smaller element

        // Rearrange the array to ensure smaller elements are on the left of pivot
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);  // Swap elements to move smaller elements to the left
            }
        }

        // Swap the pivot element to its correct position
        swap(arr[i + 1], arr[high]);
        return i + 1;  // Return the index of the pivot
    }

    // Function to perform QuickSort
    void sort(vector<int>& arr, int low, int high) {
        if (low < high) {
            // Partition the array and get the index of the pivot
            int pivotIndex = partition(arr, low, high);

            // Recursively sort the left and right sub-arrays
            sort(arr, low, pivotIndex - 1);  // Sort the left part
            sort(arr, pivotIndex + 1, high);  // Sort the right part
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
    QuickSort sorter;  // Create an object of QuickSort class

    cout << "Original array: ";
    sorter.printArray(arr);  // Print original array

    sorter.sort(arr, 0, arr.size() - 1);  // Call the sort function to sort the array

    cout << "Sorted array: ";
    sorter.printArray(arr);  // Print the sorted array

    return 0;
}
