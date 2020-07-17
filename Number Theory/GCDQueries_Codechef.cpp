#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define mod 1000000007 
ll power(ll x,ll y,ll mo)
{ 
    ll res=1;
    while(y)
    {
        if(y%2)
        {
            res=((res%mo)*(x%mo))%mo;
            y--;
        }
        else
        {
            x=((x%mo)*(x%mo))%mo;
            y=y/2;
        }
    }
    return (res%mo);
}
ll gcd(ll p,ll q,ll n)
{
    if(p==q)
    {
        return ((power(p,n,mod)%mod)+(power(q,n,mod)%mod));
    }
    else
    {
       ll i,cand=1;
       ll num=p-q;
       for(i=1;i*i<=num;i++)
       {
           if(num%i==0)
           {
               ll temp=(power(p,n,i)+power(q,n,i))%(i);
               if(temp==0) cand=max(cand,i);
               temp=(power(p,n,num/i)+power(q,n,num/i))%(num/i);
               if(temp==0) cand=max(cand,num/i);
               
           }
       }
       //cout<<cand<<" ";
       return cand%mod;
    }
}
int main()
{ 
    ll t;
    cin>>t;
    while(t--)
    {
    ll a,b,n;
    cin>>a>>b>>n;
    cout<<(gcd(a,b,n)%mod)<<"\n";
    }
    return 0;
}