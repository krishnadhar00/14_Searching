// 1. Binary search is a search algorithm used to find the position of a target value within a sorted array. It works by repeatedly dividing the search interval in half until the target value is found or the interval is empty. The search interval is halved by comparing the target element with the middle value of the search space.
// 2. Array must be sorted.

#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>&v, int target)
{
    int low = 0;  // start of search space 
    int high = v.size()-1;   // end of search space.
    while(low<=high)
    {
        // Calculate the midpoint of the search space.
        // int mid = (low+high)/2;      // It normal calculating mid
        int mid = low + (high - low)/2; // modified mid to tackle overflow conditions.

        if(v[mid]==target)
        {
            return mid;
        }
        else if(v[mid]<target)
        {
            // discard the left of mid.
            low = mid+1;
        }
        else
        {
            // discard the right of mid.
            high = mid-1;
        }
    }
    return -1;
}

int binarySearchRecursive(vector<int>&v, int target, int low, int high)
{
    if(low>high)
    {
        return -1;
    }
    // int mid = (low+high)/2;
    int mid = low + (high-low)/2; // modified mid to tackle overflow.
    if(v[mid]==target)
    {
        return mid;
    }
    else if(v[mid]<target)
    {
        return binarySearchRecursive(v,target,mid+1,high);
    }
    else
    {
        return binarySearchRecursive(v,target,low, mid-1);
    }
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

    // int a = binarySearch(v,target);

    int a = binarySearchRecursive(v,target,0,n-1);

    cout<<"Element present at index : "<<a<<endl;
}

// Iterative binary search
// Time complexity : O(logn) 
// Space complexity : O(1)

// Recursive binary search
// Time complexity : O(logn)
// space complexity : O(logn)