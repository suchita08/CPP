#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main()
{
    
    
        fast;
        int t;
        cin>>t;
        while(t--)
        {
            int n,W;
            cin>>n;
            int val[n],wt[n];
            for(int i=0;i<n;i++) cin>>wt[i];
            for(int j=0;j<n;j++) cin>>val[j];
            cin>>W;
            int dp[n+1][W+1];
            
                int i, w; 
            int K[n + 1][W + 1]; 
  
            // Build table K[][] in bottom up manner 
            for (i = 0; i <= n; i++)  
            { 
                for (w = 0; w <= W; w++)  
                { 
                    if (i == 0 || w == 0) 
                        K[i][w] = 0; 
                    else if (wt[i - 1] <= w) 
                        K[i][w] = max(val[i - 1] 
                                  + K[i - 1][w - wt[i - 1]], 
                                  K[i - 1][w]); 
                    else
                        K[i][w] = K[i - 1][w]; 
                } 
            } 
          
            cout<< K[n][W]<<"\n"; 
        }
	return 0;
}