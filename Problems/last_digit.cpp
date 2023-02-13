//https://www.spoj.com/problems/LASTDIG/
#include <iostream>
using namespace std;


unsigned long long power(unsigned long long a, unsigned long long b)
{
    a %= 10;    
    unsigned long long result = 1;
    while(b > 0)
    {
        if(b & 1)
        {
            result = ((result % 10) * a) % 10;
        }

        a = (a*a) % 10;
        b >>= 1;
    }
    return result;
}


int main(int argc, char **argv)
{

    int n;
    cin>>n;
    for(int idx = 0; idx < n; idx++)
    {
        int a, b;
        cin>>a>>b;
        cout<<power(a, b) % 10 <<"\n";
    }

    return 0;
}