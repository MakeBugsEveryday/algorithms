#include<iostream>

using namespace std;


void Swap(int arr[], int idxA, int idxB)
{
    int temp = arr[idxA];
    arr[idxA] = arr[idxB];
    arr[idxB] = temp;
}

/* 
上浮，由下至上的堆有序化
（大顶堆）某个节点比父节点更大，破坏了平衡
 */
void Swim(int arr[], int k)
{
    while (k > 1 && arr[k] > arr[k/2])
    {
        // 交换 k 和 k/2
        Swap(arr, k, k/2);
        k = k/2;
    }
}

/* 
下沉，由上至下的有序化
（大顶堆）某个节点比子节点更小，破坏了平衡
 */
void Sink(int arr[], int len, int k)
{
    // 边界条件，(即k为堆的倒一层)
    while (2 * k <= len)
    {
        // 左子节点
        int j = 2 * k;
        if (j < len && arr[j] < arr[j+1])
        {
            // 选择更大的一个子节点
            j++;
        }
        // 如果父节点已经比子节点大了，则忽略
        if (arr[k] >= arr[j])
        {
            break;
        }
        // 交换父子节点
        Swap(arr, k, j);
        // 更新k
        k = j;
    }
}

/* 堆排序 */
void HeapSort(int arr[], int len)
{    
    // 数组从右至左，调用sink构造子堆，特别的叶子节点不需要sink操作
    for (size_t i = len / 2; i >= 1; i--)
    {
        Sink(arr, len, i);
    }
    
    // 修复堆
    // 首先将堆顶的元素和数组的尾部元素交换，将每次都从最高的点插入堆尾的元素
    int N = len;
    while (N > 1)
    {
        /* code */
        Swap(arr, 1, N--);
        Sink(arr, N, 1);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {0, 4,7,8,3,9,10, 19,2,1};
    HeapSort(arr, 9);

    for (size_t i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
