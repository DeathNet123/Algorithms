#include<iostream>
#include<vector>
#include<stack>

using namespace std;



void balanced(int N, vector<string>& cases, string proc )
{
    if(N == 0)
    {
        cases.push_back(proc);
        return;
    }
        
    balanced(N - 1, cases, proc + "(");    
    balanced(N - 1, cases, proc + ")");
}

bool ok(string proc)
{
    stack<char> stacks;

    for(char c : proc)
    {
        if(c == '(')
        {
            stacks.push(c);
        }
        else if(stacks.empty()) return false;
        else stacks.pop();
    }
    if(stacks.empty()) return true;
    return false;
}

vector<string> balanced(int N)
{
    stack<string> stacks;
    vector<string> cake;
    vector<string> life;
    balanced(N*2, cake, "");
    for(int idx = 0; idx < cake.size(); idx++)
    {
        if(ok(cake[idx])) life.push_back(cake[idx]);
    }
    return life;   
}

int main(int argc, char** argv)
{
    vector<string> com = balanced(atoi(argv[1]));

    for(string s : com)
    {
        cout<<s<<endl;
    }
    return 0;
}