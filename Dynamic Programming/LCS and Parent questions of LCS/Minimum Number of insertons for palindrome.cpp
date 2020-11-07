#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd
int number_of_insertions(string s1,string s2)
{
    int m=s1.length();
    int n=s2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return (m-dp[m][n]);
    
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
           string str2 = string(str1.rbegin(),str1.rend()); 
           // cout<<rev<<"\n";
            cout<<number_of_insertions(str1,str2)<<"\n";
            
            
        }
	return 0;
}