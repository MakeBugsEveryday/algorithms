#include<iostream>
#include<math.h>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    
    uint32_t reverse = n;
    // 剩余需要位移的数
    int s = sizeof(n) * CHAR_BIT - 1;
    // n 右移
    for (n >>= 1; n; n >>= 1)
    {   
        cout << n << " " << s << endl;
        // reverse 左移
        reverse <<= 1;
        // 最后一位
        reverse |= n & 1;
        s--;
    }
    reverse <<= s; // 当v的最高位为0的时候进行移位

    return reverse;
}

int main(int argc, char const *argv[])
{
    long long n = 1111010011100;
    reverseBits(n);
    return 0;
}
