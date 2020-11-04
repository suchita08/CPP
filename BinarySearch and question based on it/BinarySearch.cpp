#include <bits/stdc++.h>
using namespace std;
int arr[35];
//Iterative way 
// int binary_search(int start,int end,int x)
// {
//     while(start<=end)
//     {
//         int mid=start+((end-start)/2);
//         if(arr[mid]==x) return mid;
//         else if(arr[mid]>x) end=mid-1;
//         else start=mid+1;
//     }
//     return  -1;
// }
//Recursive way 
int binarySearch( int start, int end, int x) 
{ 
    if (end >= start) { 
        int mid = start+ (end - start) / 2;  // ---> this is used to prevent the integer overflow.
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(start, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch( mid + 1, end, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
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
	    cout<<binarySearch(0,n-1,f)<<"\n";
	    
	    
	}
	return 0;
}