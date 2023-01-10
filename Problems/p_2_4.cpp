#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int horners_iterative(vector<int> equation, int x, int power)
{
    int result = equation[0];
    for(int idx = 1; idx <= power; idx++)
    {
        result  = (result * x) + equation[idx];
    }
    return result;
}

int horners_recursive(vector<int> equation, int x, int idx)
{
    if(idx == 0)
        return equation[idx];
    return equation[idx] + horners_recursive(equation, x, idx - 1) * x;
}

int main(int argc, char** argv)
{
    //Horner's rule solve the polynomial equation in O(n) rather than naive approach 
    //which takes O(n^2) instead.

    vector<int> equation {6, -2, 7, 5}; //filling the missing powers polynomial with zero if any of the
    printf("Answer by iteration:  %d\n", horners_iterative(equation, 4, 3));
    printf("Answer by Recursion:  %d\n", horners_recursive(equation, 4, 3));
    vector<int> equation2 {5, 0, -3, 0, 12}; //filling the missing powers polynomial with zero if any of the
    printf("Answer by iteration:%d\n", horners_iterative(equation2, -4, 4));
    printf("Answer by Recursion:  %d\n", horners_recursive(equation, -4, 4));
    return 0;
}