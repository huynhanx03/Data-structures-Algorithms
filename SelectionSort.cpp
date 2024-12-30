#include <iostream>
#include <vector>
using namespace std;

class SelectionSort {
public:
    // Function to perform selection sort
    // Takes a vector of integers as input
    void sort(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array

        // Traverse through all array elements
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;  // Assume the current index as the minimum index

            // Find the smallest element in the unsorted part of the array
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;  // Update the index of the smallest element
                }
            }

            // Swap the found minimum element with the element at index i
            swap(arr[i], arr[minIdx]);
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
    vector<int> arr = {64, 25, 12, 22, 11};  // Sample array
    SelectionSort sorter;  // Create an object of SelectionSort class

    cout << "Original array: ";
    sorter.printArray(arr);  // Print original array

    sorter.sort(arr);  // Call the sort function to sort the array

    cout << "Sorted array: ";
    sorter.printArray(arr);  // Print the sorted array

    return 0;
}
