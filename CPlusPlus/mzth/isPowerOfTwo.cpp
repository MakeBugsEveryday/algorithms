#include<iostream>

using namespace std;

bool isPowerOfTwo(unsigned num)
{
    if (num == 0)
    {
        return false;
    }

    if (num > 2 && num % 2 != 0)
    {
        return false;
    }
     
    return isPowerOfTwo(num / 2);
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << "i: " << i << " " << isPowerOfTwo(i) << endl;
    }
    
    return 0;
}
