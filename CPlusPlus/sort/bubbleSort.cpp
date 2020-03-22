#include<iostream>
using namespace std;

void BubbleSort(int arr[], int len) 
{
    // 外层 len 趟
    for (size_t i = 0; i < len; i++)
    {
        // 内层不断交换相邻元素，进行冒泡
        for (size_t j = 0; j < len - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                // 交换
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    
    cout<<"Hello world"<<endl;
    int arr[] = {4,7,8,3,0};
    BubbleSort(arr, 5);

    for (size_t i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}