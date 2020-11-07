#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Given two strings X and Y. The task is to find the length of the longest common substring.
//Example:: 2
// 6 6
// ABCDGH
// ACDGHR
// 3 2
// ABC
// AC
int lcs(int x, int y, string s1, string s2)
{
   int dp[x+1][y+1];int res=0;
    for(int i=0;i<=x;i++) 
    {
        for(int j=0;j<=y;j++) 
        {
            if(i==0 || j==0 )
                dp[i][j]=0;
        }
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                res=max(res,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    return res;
    
}
int main()
{
    
    
        fast;
        int t;
        cin>>t;
        while(t--)
        {
            int l1,l2;
            cin>>l1>>l2;
            char a[l1],b[l2];
            for(int i=0;i<l1;i++) cin>>a[i];
            for(int j=0;j<l2;j++) cin>>b[j];
            cout<<lcs(l1,l2,a,b)<<"\n";
            
            
        }
	return 0;
}