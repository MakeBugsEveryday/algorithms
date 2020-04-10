#include<iostream>
#include<vector>
using namespace std;

/* 查找数组中只出现过一次的数字 */
int singleNumber(vector<int>& arr) {

    int num = 0;

    for (size_t i = 0; i < arr.size(); i++)
    {
        num ^= arr[i];
    }

    return num;
}

int main(int argc, char const *argv[])
{

    int arr[] = { 2, 2, 1, 4, 6};
    vector<int>vt(arr, arr + (sizeof(arr) / sizeof(arr[0])));
    cout << singleNumber(vt) <<endl;

    return 0;
}
