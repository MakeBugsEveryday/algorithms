#include<iostream>
#include<math.h>

using namespace std;

// 是否是质数, 只能被1和自身整除的数
bool isPrime(unsigned num)
{
    for (size_t i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << "i: " << i << " " << isPrime(i) << endl;
    }
    
    return 0;
}
