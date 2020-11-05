  
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::  search an element in an sorted infinite array.
// logic :: Since array is sorted, the first thing clicks into mind is binary search, but the problem here is that we don’t know size of array.If the array is infinite, that means we don’t have proper bounds to apply binary search. So in order to find position of key, first we find bounds and then apply binary search algorithm.If the array is infinite, that means we don’t have proper bounds to apply binary search. So in order to find position of key, first we find bounds and then apply binary search algorithm.
//  ->if it is greater than high index element then copy high index in low index and double the high index.
//  ->if it is smaller, then apply binary search on high and low indices found.


// Time Complexity :: Let p be the position of element to be searched. Number of steps for finding high index ‘h’ is O(Log p). The value of ‘h’ must be less than 2*p. The number of elements between h/2 and h must be O(p). Therefore, time complexity of Binary Search step is also O(Log p) and overall time complexity is 2*O(Log p) which is O(Log p).
int binary_search(int arr[],int start,int end,int x)
{
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x )
        {
            //res=arr[mid];
            end=mid-1;
        }
            
        else if(arr[mid]<x)
        {
            start=mid+1;
        }
        
    }
    return res;
}
int get_upper_bound(int arr[],int key)
{
    int start=0;
    int end=1;
    while(arr[end]<key)
    {
        start=end;
        end=end*2;
    }
    return binary_search(arr,start,end,key);
}

int main()
{
    
        fast;
        int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,  
                               140, 160, 170}; 
	    int ele=10;
	    int ans=get_upper_bound(arr,ele);
	    
	    //int a1=binary_search(arr,0,high,ele);
	    
	    cout<<ans<<"\n";
	   
	return 0;
}
