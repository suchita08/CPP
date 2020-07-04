#include<bits/stdc++.h>
using namespace std;
//Binary exponentiation  is a trick which allows to calculate an using only O(logn) multiplications 

int binaryExp(int a,int b)
{
    int ans=1;
    while(b>0)
    {
        if(b%2!=0)
        {
            ans=ans*a;
            b=b-1;
        }
        else
        {
            a=a*a;
            b=b/2;
        }
    }
    return ans;
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t,i,j,k;
        cin>>t;
        while(t--)
        {
            int x,y;
            cin>>x>>y;
            cout<<binaryExp(x,y)<<"\n";
            
        }
    return 0;
    
}
