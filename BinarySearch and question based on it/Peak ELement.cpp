#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Program :: Given an array of integers. Find a peak element in it. An array element is a peak if it is NOT smaller than its neighbours. For corner elements, we need to consider only one neighbour.

// logic ::The idea is based on the technique of Binary Search to check if the middle element is the peak element or not. If the middle element is not the peak element, then check if the element on the right side is greater than the middle element then there is always a peak element on the right side. If the element on the left side is greater than the middle element then there is always a peak element on the left side. Form a recursion and the peak element can be found in log n time.


// Time Complexity :: O(logn)


int find_peak_element(int size,int arr[],int start,int end)
{
    //int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid>0 && mid<(size-1))
        {
            if(arr[mid+1]<arr[mid] && arr[mid-1]<arr[mid])
            {
                return mid;
            }
            else if(arr[mid+1]>arr[mid] )
            {
                start=mid+1;
            }
                
            else if(arr[mid]<arr[mid])
            {
                start=mid+1;
            }
        }
        else if(mid==0)
        {
            if(arr[1]<arr[0]) return 0;
            else return 1;
        }
        else if(mid==(size-1))
        {
            if(arr[size-1]>arr[size-2]) return size-1;
            else return size-2;
        }
        
    }
   // return res;
}

int main()
{
    
    
        fast;
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            int arr[n];
            for(int i=0;i<n;i++) cin>>arr[i];
    	    int ans=find_peak_element(n,arr,0,n-1);
    	    cout<<ans<<"\n";
        }
	return 0;
}