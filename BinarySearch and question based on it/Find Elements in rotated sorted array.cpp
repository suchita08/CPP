#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
int n;
int arr[34];
//Program to find element in the rotated sorted array.
//Logic ::  1.) First find  the index of minimum element.
//          2.) Run binary_search for two sorted subarray (left of the min                                  -element and right of the min element)

int countRotations(int low,int high)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;
        if(arr[next]>=arr[mid] && arr[prev]>=arr[mid])
        return mid;
        if(arr[high]>=arr[mid]) high=mid-1;
        else if(arr[mid]>=arr[low]) low=mid+1;
            
    }
}
int binary_search(int start,int end,int x)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x) end=mid-1;
        else start=mid+1;
        
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
	    
	    int ind=countRotations(0,n-1);
	    int a1=binary_search(0,ind,ele);
	    int a2=binary_search(ind,n-1,ele);
	    if(a1==a2==-1) cout<<"-1"<<"\n";
	    else if(a1==-1) cout<<a2<<"\n";
	    else if(a2==-1) cout<<a1<<"\n";
	    
	}
	return 0;
}