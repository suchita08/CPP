#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program :: Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

//logic ::If the sum of the array is odd then equal partition is not possible.If the sum is even then check if there exist a subset with the sum equal to the half of the sum of the array.
bool equal_partition(int n,int set[])
{
    long int s=accumulate(set,set+n,0);
    if(s%2==1) return false;
    else
    {
            int sum=s/2;
                
            bool subset[n + 1][sum + 1]; 
            for (int i = 0; i <= n; i++) 
                subset[i][0] = true; 
            for (int i = 1; i <= sum; i++) 
                subset[0][i] = false; 
            for (int i = 1; i <= n; i++)
            { 
                for (int j = 1; j <= sum; j++) { 
                    if (j < set[i - 1]) 
                        subset[i][j] = subset[i - 1][j]; 
                    if (j >= set[i - 1]) 
                        subset[i][j] = subset[i - 1][j] 
                                       || subset[i - 1][j - set[i - 1]]; 
                } 
            } 
        return subset[n][sum];
  
    }
          
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
            
            cout<<equal_partition(n,arr)<<"\n";
          
            //cout<< K[n][W]<<"\n"; 
        }
	return 0;
}