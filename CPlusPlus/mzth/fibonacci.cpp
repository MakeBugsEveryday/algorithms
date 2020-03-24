#include<iostream>

using namespace std;

long long Fabonacci(unsigned num)
{
    if (num == 0 || num == 1)
    {
        return num;
    }
    
    return Fabonacci(num - 1) + Fabonacci(num - 2); 
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << "i: " << i << " " << Fabonacci(i) << endl;
    }
    
    return 0;
}
