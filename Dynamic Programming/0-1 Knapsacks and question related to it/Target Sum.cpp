#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.

// Example 1:
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// There are 5 ways to assign symbols to make the sum of nums be target 3.

int  target_sum(int n,int set[],int diff)
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
            int s;
            cin>>s;
            //int s=accumulate(arr,arr+n,0);
            
            
           cout<<target_sum(n,arr,s)<<"\n";
       
        }
	return 0;
}