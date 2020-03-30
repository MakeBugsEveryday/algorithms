#include<iostream>
#include<vector>
using namespace std;

/* 判断数组是否包含重复的元素 */
bool cotainDuplicate(vector<int> arr) {

    // 将数组排序
    sort(arr.begin(), arr.end());

    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i-1])
        {
            return true;
        }    
    }
    
    return false;
}

int main(int argc, char const *argv[])
{

    int arr[] = {0, 0, 1, 2, 6, 2, 3, 4, 5};
    vector<int>vt(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    cout << cotainDuplicate(vt) <<endl;
    return 0;
}
