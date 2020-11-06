#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program :: Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
bool subset_sum(int n,int set[],int sum)
{
     
          bool subset[n + 1][sum + 1]; 
  
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
  
    // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) { 
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
            int s;
            cin>>s;
            cout<<subset_sum(n,arr,s)<<"\n";
          
            //cout<< K[n][W]<<"\n"; 
        }
	return 0;
}