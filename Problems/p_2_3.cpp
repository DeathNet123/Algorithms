//given a set S of n integers and an integer x.
//write algorithm that finds weather the set has 
//two integers say y and z such that x = y + z
//time complexity is O(nlgn)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool find_yz(vector<int> data, int x)
{
    for(int idx = 0; idx < data.size(); idx++)
    {
        if(binary_search(data.begin(), data.end(), x - data[idx]))
            return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    srand(time(NULL)); //seeding...
    vector<int> data;
    
    //Setting the random length of the array
    int n = rand() % 10 + 1;
    //Adding random numbers in the array and printing them...
    for(int idx = 0; idx < n; idx++)
    {
        data.push_back(rand() % n + 1);
    }
    sort(data.begin(), data.end());
    for(int idx = 0; idx < n; idx++)
    {
        cout << data[idx] <<" ";
    }
    int x = rand() % 10 + 1;
    cout<<"\nX: "<<x<<"\n";
    find_yz(data, x) == true ? cout<<"true\n": cout<<"false\n";
    return 0;
}