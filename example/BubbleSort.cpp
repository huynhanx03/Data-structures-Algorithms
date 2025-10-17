#include <iostream>
#include <vector>
using namespace std;

class BubbleSort {
public:
    // Function to perform bubble sort
    // Takes a vector of integers as input
    void sort(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array

        // Outer loop to traverse all elements of the array
        for (int i = 0; i < n-1; i++) {
            // Inner loop to compare each pair of adjacent elements
            for (int j = 0; j < n-i-1; j++) {
                // If the current element is greater than the next element, swap them
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);  // Swap the elements
                }
            }
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
    BubbleSort sorter;  // Create an object of BubbleSort class

    cout << "Original array: ";
    sorter.printArray(arr);  // Print original array

    sorter.sort(arr);  // Call the sort function to sort the array

    cout << "Sorted array: ";
    sorter.printArray(arr);  // Print the sorted array

    return 0;
}
