#include<iostream>
#include<vector>
using namespace std;

/* 超过数组长度一半的元素 */
int marjorityElement(vector<int> arr) {

    int targetElement = 0;
    int count = 0;

    for (size_t i = 0; i < arr.size(); i++)
    {
        if (count == -1)
        {
            targetElement = arr[i];
            count = 1;
        }
        else
        {
             if (targetElement == arr[i])
             {
                 count++;
             }
             else
             {
                 count--;
             }
        }
    }
    
    return targetElement;
}

int main(int argc, char const *argv[])
{

    int arr[] = { 1,2,2,2,1,4,2};
    vector<int>vt(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    cout << marjorityElement(vt) <<endl;
    return 0;
}
