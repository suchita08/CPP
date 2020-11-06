#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Coin Change Problem Minimum Numbers of coins
// Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?
// Example:

// Input: coins[] = {25, 10, 5}, V = 30
// Output: Minimum 2 coins required
// We can use one coin of 25 cents and one of 5 cents 

int count_ways(int n,int arr[],int s)
{
    int dp[n+1][s+1];
    for (int i = 0; i <= s; i++) 
                dp[0][i] = INT_MAX-1; 
            for (int i = 1; i <= n; i++) 
                dp[i][0] = 0; 
    for(int j=1;j<=s;j++)
    {
        if(j%arr[0]==0)
        dp[1][j]=j/arr[0];
        else
        dp[1][j]=INT_MAX-1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
          if (j < arr[i - 1]) 
                        dp[i][j] = dp[i - 1][j]; 
                    if (j >= arr[i - 1]) 
                        dp[i][j] = min(dp[i - 1][j], 
                                      1+dp[i][j - arr[i - 1]]); 
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