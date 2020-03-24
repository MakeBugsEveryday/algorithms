#include<iostream>
using namespace std;

void Swap(int arr[], int idxA, int idxB)
{
    int temp = arr[idxA];
    arr[idxA] = arr[idxB];
    arr[idxB] = temp;
}

// 切分
int participate(int arr[], int low, int high)
{
    int i = low, j = high + 1;
    // 第一个元素作为切分元素
    int compare = arr[low];
    // 切分
    while (true)
    {
        // 查找比compare小的元素下标
        while (arr[++i] < compare)
        {
            // 注意边界
            if (i == high)
            {
                break;
            }
        }

        // 查找比compare大的元素小标
        while (arr[--j] > compare)
        {
            // 注意边界
            if (j == low)
            {
                break;
            }
        }
        
        // 左右相遇，退出主循环
        if (i >= j)
        {
            break;
        }
        
        // 交换 i 和 j
        Swap(arr, i, j);
    }
    
    // j 和 low 交换
    Swap(arr, j, low);
    return j;
}

// 快速排序
void QuickSort(int arr[], int len, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    
    // 切分
    int j = participate(arr, low, high);
    cout << "j: " << j << " low: " << low << " high: " << high << endl;
    for (size_t i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // 将左半部分排序【low, j-1】
    QuickSort(arr, len, low, j-1);
    // 将右半部分排序【j+1, high】
    QuickSort(arr, len, j+1, high);
}

int main(int argc, char const *argv[])
{
    
    int arr[] = {4, 7, 8, 3, 9, 1};
    int arrCount = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, arrCount, 0, arrCount - 1);

    for (size_t i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
    return 0;
}
