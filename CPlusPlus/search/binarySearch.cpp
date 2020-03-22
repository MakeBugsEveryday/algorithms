#include<iostream>
using namespace std;

// 折半查找
int BinarySearch(int arr[], int len, int target)
{
    int low = 0;
    int high = len - 1;

    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        if (arr[middle] == target)
        {
            return middle;
        }
        else if (arr[middle] < target)
        {
            low = middle + 1;
        }
        else if (arr[middle] > target)
        {
            high = middle - 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    
    int arr[] = {0, 1, 5, 8, 10, 20, 50, 100};
    cout << "found index: " << BinarySearch(arr, 8, 8) << endl;
    cout << "found index: " << BinarySearch(arr, 8, 9) << endl;
    cout << "found index: " << BinarySearch(arr, 8, 50) << endl;
    cout << "found index: " << BinarySearch(arr, 8, 100) << endl;
    return 0;
}
