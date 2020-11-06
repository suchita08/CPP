#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
int n;
int arr[34];
//Program :: Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x. Write efficient functions to find floor of x.
//Logic :: The idea is simple, traverse through the array and find the first            element greater than x. The element just before the found element is         the floor of x.

int modified_binary_search(int start,int end,int x)
{
    int res;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x) return arr[mid];
        else if(arr[mid]>x )
        {
            end=mid-1;
        }
            
        else if(arr[mid]<x)
        {
            start=mid+1;
            res=arr[mid];
        }
        
    }
    return res;
}
int main()
{
    
    fast;
	int t;
	cin>>t;
	while(t--)
	{
	   
	    cin>>n;
	    
	    for(int i=0;i<n;i++) cin>>arr[i];
	    int ele;
	    cin>>ele;
	    
	    
	    int a1=modified_binary_search(0,n-1,ele);
	    
	    cout<<a1<<"\n";
	    
	}
	return 0;
}