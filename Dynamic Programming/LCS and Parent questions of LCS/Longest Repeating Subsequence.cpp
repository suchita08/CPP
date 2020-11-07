#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//Program ::Longest Repeating Subsequence
// Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
// Example:
// Input: str = "aab"
// Output: "a"
// The two subsequence are 'a'(first) and 'a' 
// (second). Note that 'b' cannot be considered 
// as part of subsequence as it would be at same
// index in both.
int longest_repeating_subsequence(string s1,string s2)
{
    int m=s1.length();
    int n=s1.length();
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
            if(s1[i-1]==s2[j-1] && i!=j)
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
    
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
          // string rev = string(str1.rbegin(),str1.rend()); 
           // cout<<rev<<"\n";
            cout<<longest_repeating_subsequence(str1,str1)<<"\n";
            
            
        }
	return 0;
}