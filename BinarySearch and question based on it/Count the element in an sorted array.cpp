#include <bits/stdc++.h>
using namespace std;
int arr[35];
//Program to find the count of elements in an sorted array.
//Logic ::  find the first occurence of an element and the last occurence of element in an sorted array then the answer will be (last-first+1).
int binary_search_for_lastoccurence(int start,int end,int x)
{
    int res=-1;
    
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if(arr[mid]==x)
        {
            res= mid;
            start=mid+1;
        }
        else if(arr[mid]>x) end=mid-1;
        else start=mid+1;
    }
    return  res;
}
int binary_search_for_firstoccurence(int start,int end,int x)
{
    int res=-1;
    
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if(arr[mid]==x)
        {
            res= mid;
            end=mid-1;
        }
        else if(arr[mid]>x) start=mid+1;
        else end=mid-1;
    }
    return  res;
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
	    int first,last;
	    first=binary_search_for_firstoccurence(0,n-1,f);
	    last=binary_search_for_lastoccurence(0,n-1,f);
	    if(last==-1 && first==-1) cout<<"0"<<"\n";
	    else cout<<(last-first+1)<<"\n";
	    
	}
	return 0;
}