#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Given a string s and a string t, check if s is subsequence of t.

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
bool sequence_pattern_matching(string s1,string s2)
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
    return (dp[m][n]==m);
    
}
int main()
{
    
    
        fast;
        int t;
        cin>>t;
        while(t--)
        {
            
            string str1,str2;
            cin>>str1>>str2;
          // string rev = string(str1.rbegin(),str1.rend()); 
           // cout<<rev<<"\n";
            cout<<sequence_pattern_matching(str1,str2)<<"\n";
            
            
        }
	return 0;
}