#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program :: Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 
int  subset_sum(int n,int set[],int sum)
{
                
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
            int diff = INT_MAX;
     
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j=sum/2; j>=0; j--)
    {
       
        if (subset[n][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
       
 
          
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
            int s=accumulate(arr,arr+n,0);
            
            
           cout<<subset_sum(n,arr,s)<<"\n";
       
        }
	return 0;
}