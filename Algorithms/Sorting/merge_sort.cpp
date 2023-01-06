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

    for(int k = p; k <= r; k++)
    {
        if(l < L.size() && L[l] <= R[m])
        {
            data[k] = L[l++];
        }
        else
        {
            data[k] = R[m++];
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
    int n = rand() % 10 + 1;
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
    for(int idx = 0; idx < n; idx++)
    {
        cout << data[idx] <<" ";
    }
    cout<<"\n";

    return 0;
}