//https://www.spoj.com/problems/ZSUM/
#include<iostream>

using namespace std;

unsigned long long power_mod(unsigned long long n, unsigned long long m, unsigned long long mod)
{
    n = n % mod;
    unsigned long long result = 1;
    while(m > 0)
    {
        if(m & 1)
        {
            result = ((result % mod) * n) % mod;
        }
        //since the previous n will always be mod no need to add it explicitly..
        n = (n * n) % mod;
        m >>= 1;
    }      
    return result;
}


int main(int argc, char **argv)
{
    while (true)
    {
        unsigned long long n, k;
        cin>>n>>k;
        if(n == 0 && k == 0) break;
        unsigned long long z = 0;
        unsigned long long p = 0;
        unsigned long long s = 0;
        unsigned long long p1 = 0;
        unsigned long long s1 = 0;
        unsigned long long p2 = 0;
        unsigned long long s2 = 0;

        for(int idx = n-2; idx <= n; idx++)
        {
            unsigned long long r1 = power_mod(idx, idx, 10000007);
            s += r1;
            if(idx == k)
                p += r1;
            else p += power_mod(idx, k, 10000007);
            if(idx <= n-1)
            {
                s1 = s;
                p1 = p;
            }
            if(idx <= n-2)
            {
                s2 = s;
                p2 = p;
            }
        }
        z = s + p + s1 + p1 - (2 *(s2 + p2));
        cout<< z % 10000007<<'\n';
    }
    
    return 0;
}