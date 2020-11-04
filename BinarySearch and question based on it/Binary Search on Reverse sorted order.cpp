#include <bits/stdc++.h>
using namespace std;
int arr[35];
//Program to search the element from an element from an array which is sorted in reverse order.(in descending order)
int binary_search(int start,int end,int x)
{
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        //Note :: here the formula for finding the mid value is not (start+end)/2  ,instead it is 
        //  mid=start+(end-start)/2  this formula is used to get rid of the integer overflow.
        if(arr[mid]==x) return mid;
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
	    cout<<binary_search(0,n-1,f)<<"\n";
	    
	    
	}
	return 0;
}