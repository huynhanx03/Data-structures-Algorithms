#include <iostream>
#include <vector>
using namespace std;

class InsertionSort {
public:
    // Function to perform insertion sort
    // Takes a vector of integers as input
    void sort(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array

        // Traverse through all array elements starting from the second element
        for (int i = 1; i < n; i++) {
            int key = arr[i];  // Take the current element as the key
            int j = i - 1;

            // Move elements of arr[0..i-1], that are greater than key, to one position ahead
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];  // Shift the element to the right
                j--;
            }
            
            // Place the key in the correct position
            arr[j + 1] = key;
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
    InsertionSort sorter;  // Create an object of InsertionSort class

    cout << "Original array: ";
    sorter.printArray(arr);  // Print original array

    sorter.sort(arr);  // Call the sort function to sort the array

    cout << "Sorted array: ";
    sorter.printArray(arr);  // Print the sorted array

    return 0;
}
