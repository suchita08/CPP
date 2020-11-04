#include <bits/stdc++.h>
using namespace std;
int arr[35];
//Program to find the first occurence of the given element 
//Logic ::  First use the binary search to find the element ,then when we find it store it in the variable and update the value end and call the binary search till start<=end.Here we update the value of end as we need to find the first occurence and the array is sorted in ascending order.
int binary_search(int start,int end,int x)
{
    int res=-1;
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if(arr[mid]==x)
        {
            res=mid;
            end=mid-1;
        }
        else if(arr[mid]>x) end=mid-1;
        else start=mid+1;
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
	    cout<<binary_search(0,n-1,f)<<"\n";
	    
	    
	}
	return 0;
}