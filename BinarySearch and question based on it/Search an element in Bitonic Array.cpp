#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Program :: Search an element in the bitonic array (an array  which is initially increasing and then decreasing, for every i>0 arr[i]!=arr[i+1])

// logic ::The idea is to find the bitonic point k which is the index of the maximum element of given sequence. If the element to be searched is greater than maximum element return -1, else search the element in both halves. Below is the step by step algorithm on how to do this.
//i) Find the bitonic point in the given array, i.e the maximum element in the given bitonic array. This can be done in log(n) time by modifying the binary search algorithm. You can refer to this post on how to do this.If the element to be searched is equal to the element at bitonic point then print the index of bitonic point.
//ii) If the element to be searched is greater than element at bitonic point then element does not exist in the array.
//iii)If the element to be searched is less than element at bitonic point then search for element in both half of the array using binary search.


// Time Complexity :: O(logn)


 int  findMaximum(int arr[],int low,int high)
{
     if (low == high)  
        return low; 
    if ((high == low + 1) && arr[low] >= arr[high])  
        return low;  
      
    if ((high == low + 1) && arr[low] < arr[high])  
        return high;  
      
    int mid = (low + high)/2; 
    if ( arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])  
        return arr[mid];  
    if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])  
        return findMaximum(arr, low, mid-1); 
    else 
        return findMaximum(arr, mid + 1, high); 
}
int binary_search_assc(int arr[],int start,int end,int x)
{
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x) end=mid-1;
        else start=mid+1;
    }
    return res;
}
int binary_search_desc(int arr[],int start,int end,int x)
{
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x) start=mid+1;
        else end=mid-1;
    }
    return res;
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
            int ele;
            cin>>ele;
    	    int ans=findMaximum(arr,0,n-1);
    	    if(ele==arr[ans]) cout<<ans<<"\n";
    	    else if(ele>arr[ans]) cout<<"-1"<<"\n";
    	    else
    	    {
    	        int a1=binary_search_assc(arr,0,ans-1,ele);
    	        if(a1!=-1) cout<<a1<<"\n";
    	        else cout<<binary_search_desc(arr,ans+1,n-1,ele)<<"\n";
    	        
    	    }
        }
	return 0;
}