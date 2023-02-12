#include<iostream>
#include<vector>

using namespace std;

vector<int> fib;

void fill_fib(int k)
{
    fib.push_back(0);
    fib.push_back(1);

    for(int idx = 2; idx <= k; idx++)
    {
        fib.push_back(fib[idx - 1] + fib[idx - 2]);
    }

}

string encode_fib(int n)
{
    bool flag = false;
    string code = "";

    for(int idx = 29; idx >= 2 ; idx--)
    {
        if(fib[idx] <= n)
        {
            flag = true;
            code  = "1" +  code ;
            n = n - fib[idx];
        }
        else if(flag)
        {
            code = "0" + code ;
        }
    }

    return code + "1";
}

int main(int argc, char **argv)
{
    fill_fib(30);
    cout<<encode_fib(atoi(argv[1]));
    return 0;
}