#include<iostream>
using namespace std;


long long power(int n, int m)
{
    long long res = 1;
    int power = n;
    while(m > 0)
    {
        if(m & 1)
            res *= power;
        m = m >> 1;
        power *= power;
    }
    return res;
}

int main(int argc, char **argv)
{
    long long res = power(3, 13);
    cout<< res;
    return 0;
}