#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long int
int F[1000001];
#define mod 1000000009
//Binomial cofficient using modulo 
//This method is used to find C(n,k)%P  iff n<P 
//Here 1LL is used to overcome the overflow 
int power(int a,int b)
{
    int res=1;
    while(b>0)
    {
        if(b%2)
        {
            res=(res*1LL*a)%mod;
            b--;
        }
        else
        {
            a=(a*1LL*a)%mod;
            b=b/2;
        }
    }
    return res;
}
int C(int x,int y)
{ 
    int res=1;
    if(y>x) return 0;
    else
    {
        // int res=1;
        res=F[x];
        res=(res*1LL*power(F[y],mod-2))%mod;
        res=(res*1LL*power(F[x-y],mod-2))%mod;
    }
    return res;
}
int main()
{
    
    int t,i;
    F[0]=F[1]=1;
    for(i=2;i<=1000000;i++)
    F[i]=(F[i-1]*1LL*i)%mod;
    
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cout<<C(n,k)<<"\n";
    }
    
    return 0;
}
