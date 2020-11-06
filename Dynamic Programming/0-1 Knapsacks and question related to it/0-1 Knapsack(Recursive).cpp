#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int knapsack(int n,int val[],int wt[],int w)
{
    if(n==0 || w==0 ) return 0;
    
    else if(wt[n-1]<=w)
    {
        return max((val[n-1]+knapsack(n-1,val,wt,w-wt[n-1])),knapsack(n-1,val,wt,w));
        
    }
    else
    {
        knapsack(n-1,val,wt,w);
    }
}
int main()
{
    
    
        fast;
        int t;
        cin>>t;
        while(t--)
        {
            int n,W;
            cin>>n;
            int val[n],wt[n];
            for(int i=0;i<n;i++) cin>>wt[i];
            for(int j=0;j<n;j++) cin>>val[j];
            cin>>W;
            cout<<knapsack(n,val,wt,W)<<"\n";
        }
	return 0;
}