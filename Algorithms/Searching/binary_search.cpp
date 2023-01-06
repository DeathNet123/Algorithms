#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool binary_search(int s, int e, int key, std::vector<int> data)
{
    if (s <= e)
    {
        int mid = (s + e) / 2;
        if(data[mid] == key) return true;
        else if(data[mid] > key) return binary_search(s, mid - 1, key, data);
        else return binary_search(mid + 1, e, key, data);
    }
    return false;
}

int main(int argc, char** argv)
{
    srand(time(NULL)); //seeding...
    vector<int> data;
    
    //Setting the random length of the array
    int n = rand() % 10 + 1;
    
    //Adding random numbers in the array...
    for(int idx = 0; idx < n; idx++)
    {
        data.push_back(rand() % n + 1);
    }

    int key = rand() % n + 1; //get they key to search for
    sort(data.begin(), data.end()); //binary search works only on sorted data
    
    for(int idx = 0; idx < n; idx++)
        cout<<data[idx]<<" ";
    cout<<"\n";

    cout<<"Searching for " << key<<'\n';
    binary_search(0, data.size() - 1, key, data) == true? cout<<"true\n" : cout<<"false\n";

    return 0;
}