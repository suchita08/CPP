#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
int n;
int arr[34];
//Program to find the count of rotations in an sorted array.
//Logic ::  1.) No. of rotations is equal to the index of minimum element.
//          2.) Element will be smaller if its previous and next element both                   are larger .
//          3.) Minimum element will always lies int the unsorted subarray (the             array divided after finding the mid index).Condition for sorted             subarray:-  
                //   arr[start]<arr[mid]  or  arr[mid]<arr[end];

int countRotations(int low,int high)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;
        //if both next and previous element are greater than the mid element then it will be minimum element.
        if(arr[next]>=arr[mid] && arr[prev]>=arr[mid])
        return mid;
        //if the right subarray are sorted than the minimum element will be lies on the left subarray (which is unsorted array),so, we need to search for the left subarray only.
        if(arr[high]>=arr[mid]) high=mid-1;
        //if the leftt subarray are sorted than the minimum element will be lies on the right subarray (which is unsorted array),so, we need to search for the right subarray only.
        else if(arr[mid]>=arr[low]) low=mid+1;
            
    }
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
	    cout<<countRotations(0,n-1)<<"\n";
	    
	}
	return 0;
}