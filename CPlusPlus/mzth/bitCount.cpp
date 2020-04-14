#include<iostream>
#include<math.h>

using namespace std;

// 计算bit位数
int bitCount(int num) {
    
    if (num == 0) {
        return 0;
    }
    
    if (num == 1) {
        return 1;
    }
    
    int bitNum = 0;
    
    while(num) {
        
        num &= num - 1;
        bitNum ++;
    }
    
    return bitNum;
}

int main(int argc, char const *argv[])
{
    cout << bitCount(7) << endl;
    return 0;
}
