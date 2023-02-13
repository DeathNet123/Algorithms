//https://codeforces.com/problemset/problem/630/I
#include<iostream>
#include<cmath>
using namespace std;


unsigned long long power(unsigned long long n, unsigned long long m)
{
    unsigned long long result = 1;

    while (m > 0)
    {
        if(m & 1)
        {
            result = result * n;
        }
        n *= n;
        m >>= 1;
    }

    return result;
}

unsigned long long ways(unsigned long long n )
{
    unsigned long long blocks = (2*n) - 2;
    blocks = blocks - n + 1; //no of blocks without n successive cars
    //case of extreme when n cars are at start or at end of line 
    unsigned long long case1 = 3 * power(4ULL, blocks - 1);
    case1 += case1;
    //case when n cars are somewhere in middle of line..
    unsigned long long case3 = 9 * power(4ULL, blocks - 2);
    case3 *= (blocks - 2); 

    return case1 + case3;
}

int main(int argc, char **argv)
{
    unsigned long long n;
    cin >> n;
    cout<<ways(n);
    return 0;
}