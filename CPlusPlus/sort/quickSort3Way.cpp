#include<iostream>
using namespace std;

void Swap(int arr[], int idxA, int idxB)
{
    int temp = arr[idxA];
    arr[idxA] = arr[idxB];
    arr[idxB] = temp;
}

typedef struct Index
{
    int j;
    int left;
    int right;
} ThreeWayIndex;


ThreeWayIndex* ThreeWayParticipate(int arr[], int len, int low, int high)
{
    int j = low + 1;
    // 锚点
    int compare = arr[low];

    while (j <= high)
    {
        if (arr[j] < compare)
        {
            // j 和 low 右移
            Swap(arr, j++, low++);
        }
        else if (arr[j] > compare)
        {
            // 交换 j 和 high
            Swap(arr, j, high--);
        }
        else
        {
            // 相等
            j++;
        }
    }

    ThreeWayIndex *idx = new ThreeWayIndex();
    idx->j = j;
    idx->left = low;
    idx->right = high;
    return idx;
}

// 快速排序
void QuickSort3Way(int arr[], int len, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    
    ThreeWayIndex *k = ThreeWayParticipate(arr, len, low, high);

    //cout << "k: " << k << " low: " << low << " high: " << high << endl;
    for (size_t i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // 将左半部分排序【low, j-1】
    QuickSort3Way(arr, len, low, k->left-1);
    // 将右半部分排序【j+1, high】
    QuickSort3Way(arr, len, k->right+1, high);
}

int main(int argc, char const *argv[])
{
    
    int arr[] = {4, 7, 8, 3, 9, 1, 10};
    int arrCount = sizeof(arr) / sizeof(arr[0]);
    QuickSort3Way(arr, arrCount, 0, arrCount - 1);

    for (size_t i = 0; i < arrCount; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
