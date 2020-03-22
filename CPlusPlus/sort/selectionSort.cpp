#include<iostream>
using namespace std;

/* 第一次从待排序的数据元素中选出最小（或最大）的一个元素，
存放在序列的起始位置，然后再从剩余的未排序元素中寻找到最小（大）元素，
然后放到已排序的序列的末尾 */
void SelectionSort(int arr[], int len)
{
    // 外层 len - 1 趟
    for (size_t i = 0; i < len; i++)
    {
        // 查找最小值
        int min = i;
        // 选择查找比min更小的
        for (size_t j = i+1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        // min 和 i 不相等，则交换 min 和 i
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {0, 4,7,8,3,9,10, 19};
    SelectionSort(arr, 7);

    for (size_t i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

