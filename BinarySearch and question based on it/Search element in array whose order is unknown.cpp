#include <bits/stdc++.h>
using namespace std;
int arr[35];
//Program to search for the element when the order of array is not known.
//Logic ::  If the array contains only one element ,then simply check it,else check for the order by comparing the first and last element of the array and then accordingly run the binary search function.
int binary_search_for_ascending(int start,int end,int x)
{
    
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>x) end=mid-1;
        else start=mid+1;
    }
    return  -1;
}
int binary_search_for_descending(int start,int end,int x)
{
    
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>x) start=mid+1;
        else end=mid-1;
    }
    return  -1;
}
int main()
{
    
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++) cin>>arr[i];
	    int f;
	    cin>>f;
	    if(n==1)
	    {
	        if(arr[0]==f)
	        cout<<"0"<<"\n";
	        else 
	        cout<<"-1"<<"\n";
	    }
	    else
	    {
	        if(arr[0]>arr[n-1])
	        cout<<binary_search_for_descending(0,n-1,f)<<"\n";
	        else
	        cout<<binary_search_for_ascending(0,n-1,f)<<"\n";
	    }
	    
	    
	}
	return 0;
}