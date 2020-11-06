#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Rod Cutting Problem
//  Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the  maximum value obtainable by cutting up the rod and selling the pieces. 
// Example: 
// if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


// length   | 1   2   3   4   5   6   7   8  
// --------------------------------------------
// price    | 1   5   8   9  10  17  17  20
int main()
{
    
    
        fast;
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            int val[n],len[n];
            for(int i=0;i<n;i++) cin>>len[i];
            for(int j=0;j<n;j++) cin>>val[j];
            int dp[n+1][n+1];
            
                int i, w; 
            int K[n + 1][n+ 1]; 
  
            // Build table K[][] in bottom up manner 
            for (i = 0; i <= n; i++)  
            { 
                for (w = 0; w <= n; w++)  
                { 
                    if (i == 0 || w == 0) 
                        K[i][w] = 0; 
                    else if (len[i - 1] <= w) 
                        K[i][w] = max(val[i - 1] 
                                  + K[i][w - len[i - 1]], 
                                  K[i - 1][w]); 
                    else
                        K[i][w] = K[i - 1][w]; 
                } 
            } 
          
            cout<< K[n][n]<<"\n"; 
        }
	return 0;
}