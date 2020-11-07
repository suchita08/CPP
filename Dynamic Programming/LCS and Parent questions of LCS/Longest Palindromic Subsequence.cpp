#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Given a String, find the longest palindromic subsequence



int lcs(int x, int y, string s1, string s2)
{
   int dp[x+1][y+1];
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
                // res=max(res,dp[i][j]);
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[x][y];
    
    
    
}
int main()
{
    
    
        fast;
        int t;
        cin>>t;
        while(t--)
        {
            string str1;
            cin>>str1;
            int l1=str1.length();
            int l2=l1;
            //string s2=" ";
            string rev = string(str1.rbegin(),str1.rend()); 
           // cout<<rev<<"\n";
            cout<<lcs(l1,l2,str1,rev)<<"\n";
            
            
        }
	return 0;
}