#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& arr, int low, int mid, int high)
{
    // 将 [low, mid], [mid+1,high]进行归并
    int i = low, j = mid+1;

    // 将arr复制到辅助数组aux
    vector<int> aux(arr);
    // for (size_t i = low; i <= high; i++)
    // {
    //     aux[i] = arr[i];
    // }
    
    // 从临时数组归并到【low, high】
    for (size_t k = low; k <= high; k++)
    {
        // 左取尽
        if (i > mid)
        {
            arr[k] = aux[j++];
        }
        // 右取尽
        else if (j > high)
        {
            arr[k] = aux[i++];
        }
        // j元素小于i元素，则归并j自增
        else if (aux[i] > aux[j])
        {
            arr[k] = aux[j++];
        }
        // j元素大于等于i元素，则归并i自增
        else
        {
            arr[k] = aux[i++];
        } 
    }
}

// 自顶向下递归归并
void Upper2DownMergeSort(vector<int>& arr, int low, int high)
{
    if (low >= high)
    {
        //cout << "break low:" << low << " high:" << high << endl;
        return;
    }

    cout << "low:" << low << " high:" << high << endl;

    int mid = low + (high - low) / 2;
    // 归并【low，mid】
    Upper2DownMergeSort(arr, low, mid);
    // 归并【mid + 1，high】
    Upper2DownMergeSort(arr, mid + 1, high);
    cout << "merge : low:" << low << " mid:" << mid << " high:" << high << endl;
    // 归并
    merge(arr, low, mid, high);
}

// 自底向上归并排序
void Down2UpperMergeSort(vector<int>& arr, int low, int high)
{
    int size = arr.size();
    // 步长，每次 * 2
    for (size_t step = 1; step < high; step*=2)
    {
        // 每次遍历 [0, step - 1], 和 [setp, 2 * step - 1]
        for (size_t idx = 0; idx < size - step; idx += 2 * step)
        {
            merge(arr, idx, idx + step - 1, min<int>(size - 1, idx + 2 * step - 1));
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,12,8,7,6,5,4,3,2,1};
    vector<int>vt(arr, arr + 10);
    // 自顶向上
    // Upper2DownMergeSort(vt, 0, vt.size() - 1);
    // 自底向上
    Down2UpperMergeSort(vt, 0, vt.size() - 1);

    for (size_t i = 0; i < vt.size(); i++)
    {
        cout << vt[i] << " ";
    }
    cout << endl;
    return 0;
}
