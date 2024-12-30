#include <iostream>
using namespace std;

// Binary Search Function
// arr[]: Sorted array
// n: Size of the array
// x: Target value to search for
int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;  // Initialize pointers

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Find middle index

        // Check if the middle element is the target
        if (arr[mid] == x) {
            return mid;  // Return the index if found
        }

        // If the target is smaller, search in the left half
        if (arr[mid] > x) {
            high = mid - 1;
        }
        // If the target is larger, search in the right half
        else {
            low = mid + 1;
        }
    }

    return -1;  // Return -1 if the element is not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};  // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);  // Get array size
    int x = 10;  // Target value to search for

    // Call binarySearch function
    int result = binarySearch(arr, n, x);

    // Print the result
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
