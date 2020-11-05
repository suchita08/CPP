#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Program :: Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array. As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.

// logic :: As the array is infinte, therefore we do not know the upper and lower bounds between which we have to find the occurrence of first ‘1’. Below is an algorithm to find the upper and lower bounds. So in order to find position of key, first we find bounds and then apply binary search algorithm.
//  ->if it is greater than high index element then copy high index in low index and double the high index.
//  ->if it is smaller, then apply binary search on high and low indices found to find the first occurence of an element.


// Time Complexity :: Let p be the position of element to be searched. Number of steps for finding high index ‘h’ is O(Log p). The value of ‘h’ must be less than 2*p. The number of elements between h/2 and h must be O(p). Therefore, time complexity of Binary Search step is also O(Log p) and overall time complexity is 2*O(Log p) which is O(Log p).
int binary_search(int arr[],int start,int end,int x)
{
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x)
        {
            res= mid;
            end=mid-1;
        }
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
        int arr[] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1}; 
	    int ele=1;
	    int ans=get_upper_bound(arr,ele);
	    
	    //int a1=binary_search(arr,0,high,ele);
	    
	    cout<<ans<<"\n";
	   
	return 0;
}
