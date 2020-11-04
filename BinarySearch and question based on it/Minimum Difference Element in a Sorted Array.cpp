#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Program ::Given a sorted array, find the element in the array which has                       minimum difference with the given number.

// logic :: Binary Search ,if the element present then the answer will be 0,else         low and high will be updated around the key element.
// Hint ::  https://youtu.be/3RhGdmoF_ac

int get_upper_bound(int arr[],int key)
{
    int start=0;
    int end=1;
    while(arr[end]<key)
    {
        start=end;
        end=end*2;
    }
    return end;
}

int binary_search(int arr[],int start,int end,int x)
{
    //int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x)
        {
           return 0;
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
    int a1=abs(arr[start]-x);
    int a2=abs(arr[end]-x);
    
    return min(a1,a2);
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
            for(int i=0;i<n;i++)
                    cin>>arr[i];
            int ele;
            cin>>ele;
	    
	    int a1=binary_search(arr,0,n-1,ele);
	    
	    cout<<a1<<"\n";
        }
	   
	return 0;
}