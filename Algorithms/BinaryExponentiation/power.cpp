#include<iostream>
using namespace std;

/*Binary Exponentiation*/
unsigned long long power(unsigned long long n, unsigned long long m)
{
    unsigned long long result = 1;

    while(m > 0)
    {
        if(m & 1)
        {
            result *= n;
        }
        m >>= 1;
        n *= n;
    }
   return result; 
}

unsigned long long power_recursive(unsigned long long n,  unsigned long long m)
{
    if(m == 0)
        return 1;
    unsigned long long result = power_recursive(n, m/2);
    if(m % 2)
    {
        return result * result  * n; //this will be run always one time in case of odd
    }
    return result * result;
}

unsigned long long power_rec(unsigned long long n, unsigned long long m)
{
    if(m == 0)
        return 1;
    unsigned long long result = power_rec(n*n, m >> 1);
    if(m & 1)
        return result * n;
    else return result;
}

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
    long long n = atoi(argv[1]);
    long long m = atoi(argv[2]);
    cout<<n<<" "<<m<<" "<<endl;
    cout<<power(n,m)<<endl;
    cout<<power_recursive(n,m)<<endl;
    cout<<power_rec(n,m)<<endl;
    cout<<"Hello : "<<power_mod(n,m, 1000)<<endl;
}