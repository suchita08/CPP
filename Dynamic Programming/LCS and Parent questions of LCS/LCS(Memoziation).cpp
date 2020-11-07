#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
//Example:: LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
//          LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4
int dp[105][105];
int lcs(char x[],char y[],int n,int m)
{
    if(n==0 || m==0) return 0;
    memset(dp,-1,sizeof(dp));
    if(dp[n][m]!=-1) return dp[n][m];
    if(x[n-1]==y[m-1]) return dp[n][m]= 1+lcs(x,y,n-1,m-1);
    else
    {
         return dp[n][m]=max(lcs(x,y,n,m-1),lcs(x,y,n-1,m));
    }
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
            cout<<lcs(a,b,l1,l2)<<"\n";
            
            
        }
	return 0;
}