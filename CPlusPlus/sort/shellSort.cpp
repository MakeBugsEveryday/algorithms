#include<iostream>
using namespace std;

// 通过插入排序演化而来， 步长
void ShellSort(int arr[], int len)
{
    // 构造shell排序步长， 序列为：3*n + 1
    int step = 1;
    while (step < len / 3)
    {
        step = step * 3 + 1;
    }

    while (step > 1)
    {
        // 将数组变为 step 有序
        for (size_t i = step; i < len; i++)
        {
            for (size_t j = i; j > 0; j-=step)
            {
                // 交换 j 和 j - step元素
                int temp = arr[j];
                arr[j] = arr[j-step];
                arr[j-step] = temp;
            }
        }
        step /= 3;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {4,7,8,3,0};
    ShellSort(arr, 5);

    for (size_t i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
