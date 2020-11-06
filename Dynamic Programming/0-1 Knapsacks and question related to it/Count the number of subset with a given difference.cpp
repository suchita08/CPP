#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::  Count the number of subset with a given difference
int  subset_sum(int n,int set[],int diff)
{
            int s=accumulate(set,set+n,0);
            int sum=(diff+s)/2;
                
           int subset[n + 1][sum + 1]; 
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
                                       +subset[i - 1][j - set[i - 1]]; 
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
            int d;
            cin>>d;
            //int s=accumulate(arr,arr+n,0);
            
            
           cout<<subset_sum(n,arr,d)<<"\n";
       
        }
	return 0;
}