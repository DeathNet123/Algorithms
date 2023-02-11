#include<iostream>
using namespace std;

/*Binary Exponentiation*/
long long power(int n, int m)
{
    long long result = 1;

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

long long power_recursive(int n, int m)
{
    if(m == 0)
        return 1;
    long long result = power_recursive(n, m/2);
    if(m % 2)
    {
        return result * result  * n; //this will be run always one time in case of odd
    }
    return result * result;
}

long long power_rec(int n, int m)
{
    if(m == 0)
        return 1;
    long long result = power_rec(n*n, m >> 1);
    if(m & 1)
        return result * n;
    else return result;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    cout<<n<<" "<<m<<" "<<endl;
    cout<<power(n,m)<<endl;
    cout<<power_recursive(n,m)<<endl;
    cout<<power_rec(n,m)<<endl;
}