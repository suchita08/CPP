#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.  
// Example: for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.

int count_ways(int n,int arr[],int s)
{
    int dp[n+1][s+1];
    for (int i = 0; i <= n; i++) 
                dp[i][0] = 1; 
            for (int i = 1; i <= s; i++) 
                dp[0][i] = 0; 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
          if (j < arr[i - 1]) 
                        dp[i][j] = dp[i - 1][j]; 
                    if (j >= arr[i - 1]) 
                        dp[i][j] = dp[i - 1][j] 
                                      +dp[i][j - arr[i - 1]]; 
        }
    }
    return dp[n][s];
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
            int a[n];
            for(int i=0;i<n;i++) cin>>a[i];
            int sum;
            cin>>sum;
            cout<<count_ways(n,a,sum)<<"\n";
            
        }
	return 0;
}