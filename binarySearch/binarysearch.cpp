#include <iostream>
using namespace std;

void binarySearch();
void binarySearchRecursive();

int main()
{
    // binarySearch();
    binarySearchRecursive();
    return 0;
};

void binarySearch()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    int left = 0;
    int right = n - 1;
    int key = 0;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (target == arr[mid])
        {
            key = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << "Element found at index => " << key << endl;
}

int binaryRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (target == arr[mid]) {
            return mid;
        } else if (arr[mid] < target) {
            return binaryRecursive(arr, mid + 1, right, target);
        } else {
            return binaryRecursive(arr, left, mid - 1, target);
        }
    }

    return -1; // Not found
}

void binarySearchRecursive(){
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int n = sizeof(arr)/sizeof(arr[0]);
    int left = 0;
    int right = n - 1;
    int target = 23;

    int elemAT = binaryRecursive(arr, left, right, target);
    cout << "Index found at => " << elemAT << endl;
}

