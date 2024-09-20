#include "bits/stdc++.h"

using namespace std;

class BinarySearch
{
    private:
        int a[100005];
        int n;

    public:
        int doBinarySearch(int value)
        {
            int left = 0;
            int right = n - 1;

            while (left <= right) 
            {
                int mid = left + (right - left) / 2;

                if (value == a[mid]) 
                    return mid;
                else if (value > a[mid])
                    left = mid + 1;
                else if (value < a[mid])
                    right = mid - 1;
            }

            return -1; // Value does not exist
        }
};

int main()
{

}