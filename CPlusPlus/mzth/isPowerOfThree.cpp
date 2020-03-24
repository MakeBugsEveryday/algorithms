#include<iostream>

using namespace std;

bool isPowerOfThree(unsigned num)
{
    int result[] = {
        0, // 0
        1, // 1
        0, // 2
        1, // 3
    };    

    if (num <= 3)
    {
        return result[num];
    }

    if (num > 3 && num % 3 != 0)
    {
        return false;
    }
     
    return isPowerOfThree(num / 3);
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << "i: " << i << " " << isPowerOfThree(i) << endl;
    }
    
    return 0;
}
