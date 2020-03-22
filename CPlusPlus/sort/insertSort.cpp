#include<iostream>
using namespace std;

/* 插入排序
第一部分包含了这个数组的所有元素，但将最后一个元素除外（让数组多一个空间才有插入的位置），
而第二部分就只包含这一个元素（即待插入元素）。
在第一部分排序完成后，再将这个最后元素插入到已排好序的第一部分中 */
void InsertSort(int arr[], int len)
{
    // 步长为1的插入排序
    int step = 1;
    for (size_t i = 1; i < len; i++)
    {
        // 查找合适的位置插入
        for (size_t j = i; j > 0; j-=step)
        {
            if (arr[j] < arr[j-step])
            {
                // 交换
                int temp = arr[j];
                arr[j] = arr[j-step];
                arr[j-step] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {4,7,8,3,0};
    InsertSort(arr, 5);

    for (size_t i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
