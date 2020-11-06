#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Program :: FInd the maximum element in the bitonic array (an array  which is initially increasing and then decreasing, for every i>0 arr[i]!=arr[i+1])

// logic ::We can modify the standard Binary Search algorithm for the given type of arrays.
//i) If the mid element is greater than both of its adjacent elements, then mid is the maximum.
//ii) If mid element is greater than its next element and smaller than the previous element then maximum lies on left side of mid. Example array: {3, 50, 10, 9, 7, 6}
//iii) If mid element is smaller than its next element and greater than the previous element then maximum lies on right side of mid. Example array: {2, 4, 6, 8, 10, 3, 1}


// Time Complexity :: O(logn)


 int  findMaximum(int arr[],int low,int high)
{
         /* Base Case: Only one element is present in arr[low..high]*/
     if (low == high)  
        return arr[low]; 
          /* If there are two elements and first is greater then  
        the first element is maximum */
    if ((high == low + 1) && arr[low] >= arr[high])  
        return arr[low];  
      
    /* If there are two elements and second is greater then  
        the second element is maximum */
    if ((high == low + 1) && arr[low] < arr[high])  
        return arr[high];  
      
    int mid = (low + high)/2; 
      
   /* If we reach a point where arr[mid] is greater than both of  
        its adjacent elements arr[mid-1] and arr[mid+1], then arr[mid]  
        is the maximum element*/
    if ( arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])  
        return arr[mid];  
      
   /* If arr[mid] is greater than the next 
        element and smaller than the previous  
        element then maximum lies on left side of mid */
    if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])  
        return findMaximum(arr, low, mid-1); 
        // when arr[mid] is greater than arr[mid-1] 
        // and smaller than arr[mid+1] 
      
    else 
        return findMaximum(arr, mid + 1, high);  
        
   
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
    	    int ans=findMaximum(arr,0,n-1);
    	    cout<<ans<<"\n";
        }
	return 0;
}