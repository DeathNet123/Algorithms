
//simple binary exponentiation with mod
#include<iostream>
using namespace std;

unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long z)
{
    x %= z;
    unsigned long long result = 1;
    while(y > 0)
    {
        if(y & 1)
        {
            result = (result % z) * x %z;
        }
        x = (x * x) % z;
        y >>= 1; 
    }
    return result;
}

int main(int argc, char **argv)
{
    int c;
    int x, y, z;
    cin >> c;
    for(int idx = 0; idx < c; idx++)
    {
        cin >> x >> y >> z;
        cout<<power(x, y, z)<<endl;
    }      
    return 0;
}