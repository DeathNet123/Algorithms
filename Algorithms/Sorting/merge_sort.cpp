#include<iostream>
#include<vector>
using namespace std;

void merge(int p, int q, int r, vector<int>& data)
{
    vector<int> L;
    vector<int> R;

    int l = 0; 
    int m = 0;
    for(int idx = p; idx <= q; idx++)
    {
        L.push_back(data[idx]);
    }
    for(int idx = q + 1; idx <= r; idx++)
    {
        R.push_back(data[idx]);
    }
    for(int idx = p; idx <= r; idx++)
    {
        if (l >= L.size())
        {
            data[idx] = R[m++];
        }
        else if (m >= R.size())
        {
            data[idx] = L[l++];
        }
        else if(L[l] <= R[m])
        {
            data[idx] = L[l++];
        }
        else
        {
            data[idx] = R[m++];
        }
    }
}

void merge_sort(int p, int q, vector<int>& data)
{
    if(p < q)
    {
        int mid = (p + q) / 2;
        merge_sort(p, mid, data);
        merge_sort(mid + 1, q, data);
        merge(p, mid, q, data);
    }
    
}

int main(int argc, char **argv)
{
    srand(time(NULL)); //seeding...
    vector<int> data;
    //Setting the random length of the array
    int n = rand() % 20 + 1;
    //Adding random numbers in the array and printing them...
    for(int idx = 0; idx < n; idx++)
    {
        data.push_back(rand() % n + 1);
        cout << data[idx] <<" ";
    }
    cout<<"\n";
    //sorting the array.
    merge_sort(0, data.size() - 1, data);
    //Printing the sorted array
    cout<<"After sorting\n";
    for(int idx = 0; idx < data.size(); idx++)
    {
        cout << data[idx] <<" ";
    }
    cout<<"\n";

    return 0;
}