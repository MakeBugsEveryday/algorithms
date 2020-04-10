#include<iostream>
#include<vector>
using namespace std;

/* 合并两个有序数组 */
void mergeTwoSortedArr(vector<int>& vt_a, int a_len, vector<int>& vt_b, int b_len) {

    int i = a_len + b_len -1;
    // 从右往左遍历， 将更大的数放 vt_a 中
    while (a_len > 0 && b_len > 0)
    {
        if (vt_a[a_len - 1] > vt_b[b_len - 1])
        {
            vt_a[i] = vt_a[a_len - 1];
            a_len--;
        }
        else
        {
            vt_a[i] = vt_b[b_len - 1];
            b_len--;
        }
        i--;
    }

    // 如果 b_len > 0
    while (b_len > 0)
    {
        vt_a[i--] = vt_b[b_len--];
    }
}

int main(int argc, char const *argv[])
{
    // a_len = 3
    int arr_a[] = {1,2,3,0,0,0};
    vector<int>vt_a(arr_a, arr_a + (sizeof(arr_a) / sizeof(arr_a[0])));
    // b_len = 3
    int arr_b[] = {2,5,6};
    vector<int>vt_b(arr_b, arr_b + (sizeof(arr_b) / sizeof(arr_b[0])));

    mergeTwoSortedArr(vt_a, 3, vt_b, 3);

    for (size_t i = 0; i < vt_a.size(); i++)
    {
        cout << vt_a[i] << " ";
    }
    
    cout << endl;
    return 0;
}
