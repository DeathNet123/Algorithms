#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

void insertion_sort(vector<int>& data)
{
    for(int idx = 1; idx < (int) data.size(); idx++)
    {
        int key = data[idx];
        int jdx = idx - 1;

        while(jdx > -1 && data[jdx] > key)
        {
            data[jdx + 1] = data[jdx];
            jdx--;
        }

        data[jdx + 1] = key;
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL)); //seeding...
    vector<int> data;
    //Setting the random length of the array
    int n = rand() % 10 + 1;
    //Adding random numbers in the array and printing them...
    for(int idx = 0; idx < n; idx++)
    {
        data.push_back(rand() % n + 1);
        cout << data[idx] <<" ";
    }
    cout<<"\n";
    //sorting the array.
    insertion_sort(data);
    //Printing the sorted array
    cout<<"After sorting\n";
    for(int idx = 0; idx < n; idx++)
    {
        cout << data[idx] <<" ";
    }
    cout<<"\n";
    
    return 0;
}