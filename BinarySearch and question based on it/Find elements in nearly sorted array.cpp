#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
int n;
int arr[34];
//Program to find element in the nearly sorted array.
//Meaning of nearly sorted array :: the element arr[i] can only be swapped with         either arr[i+1] or arr[i-1].
//Logic ::  1.) check if the mid element is equal to the ith or (i+1)th or
 //           (i-1)th element.(Also check for segementation fault i.e either
 //             mid-1<=start or not and mid+1>=end )
//          2.) Here end and start are updated by 2 instead of one as we do in normal binary search because we are checking for (i-1),i,(i+1) at each iteration.

int modified_binary_search(int start,int end,int x)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x) return mid;
        else if((mid+1)<=end && arr[mid+1]==x) return mid+1;
        else if((mid-1)>=start && arr[mid-1]==x) return mid-1;
        else if(arr[mid]>x ) end=mid-2;
        else if(arr[mid]<x) start=mid+2;
        
    }
    return -1;
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