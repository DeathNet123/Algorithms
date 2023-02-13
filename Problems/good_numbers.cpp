//https://leetcode.com/problems/count-good-numbers/
#include<iostream>
using namespace std;
typedef unsigned long long ull;
#define PRIME 4ULL
#define EVEN 5ULL

ull power_mod(ull n, ull e, ull m)
{
    ull result = 1;
    n %= m;
    while (e > 0)
    {
        if(e & 1)
            result = ((result % m)  * n) % m;
        n = (n * n) % m;
        e >>= 1;
    }
    return result;
}


int main(int argc, char **argv)
{
    ull count {0};
    cin>>count;
    ull temp = count % 2 == 1 ? 1 : 0; 
    ull even = power_mod(EVEN, count/2ULL + temp, 1000000007);
    ull odd = power_mod(PRIME, count/2ULL, 1000000007);
    ull result = ((even)  * (odd)) % 1000000007;  
    cout<<result<<endl;
    return 0;
}

