// Linear Search because it traverse all the elements for n times.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int target;
    cin>>target;
    int loc=-1;

    for(int i=0;i<n;i++)
    {
        if(v[i] == target)
        {
            loc = i;
        }
    }
    if(loc==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Elements found t index : "<<loc;
    }
}

// Time complexity : O(n)
// Space complexity : O(1)