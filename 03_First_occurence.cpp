// In this question array is given and target is given and we want the first occunce of that number 
// Input : 5 6 6 6 8 8 9 9 9 9 , target = 6 
// output : 1 (index)
// This question can also be solved using linear search but that will take O(n) T.C but by using binary search it can be solved in O(logn) time .

#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int>&v, int target)
{
    int lo = 0;
    int hi = v.size()-1;
    int ans=-1;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(v[mid]==target)
        {
            ans = mid;
            hi = mid-1;
        }
        else if(v[mid]<target)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return ans;
}
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

    int a = firstOccurence(v,target);

    cout<<"Index at : "<<a;
}