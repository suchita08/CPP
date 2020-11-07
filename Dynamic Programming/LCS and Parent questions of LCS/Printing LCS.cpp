#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Printing Longest Common Subsequence
// Given two sequences, print the longest subsequence present in both of them.
// Example:
// LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 

string lcs(int x, int y, string s1, string s2)
{
   int dp[x+1][y+1];
   string res=" ";
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
    int i=x,j=y;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            res.push_back(s1
            [i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1]) j--;
        else i--;
    }
    reverse(res.begin(),res.end());
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