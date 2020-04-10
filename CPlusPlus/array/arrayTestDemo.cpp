#include<iostream>
#include <map>
#include<string>  
#include<vector>
using namespace std;

int thirdMax(vector<int>& nums) {
        
        long max = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (n >= max) {
                if (n != max) {
                    // 降级
                    third = second;
                    second = max;
                }
                max = n;
            }
            else if(n >= second) {
                // 降级
                if (n != second) {
                    third = second;
                }
                second = n;
            }
            else if(n >= third) {
                third = n;
            }

            cout << third << " " << second << " " << max << endl;
        }

        
        if (third != LONG_MIN) {
            return third;
        }
                    
        return max;
    }

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,-2147483648};
    vector<int>vt(arr, arr + (sizeof(arr) / sizeof(arr[0])));
    cout << thirdMax(vt) << endl;
    return 0;
}
