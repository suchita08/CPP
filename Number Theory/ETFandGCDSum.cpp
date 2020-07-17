#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long int
#define mod 1000000009
int phi[1000001];
//Euler Totient Function and gcd sum 
//for n ,ans=gcd(1,n)+gcd(2,n)+gcd(3,n)+gcd(4,n)+.......+gcd(n,n)
//Lecture:21 
void init()
{
    int maxn=1000000;
    for(int i=1;i<maxn;i++)
    phi[i]=i;
    for(int i=2;i*i<=maxn;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=maxn;j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}
//Efficient way to calculate the number of times gcd(i,n)=d
int getCount(int d,int N)
{
    return phi[N/d];
}
int gcdSum(int n)
{
    int res=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int d1=i;
            int d2=n/i;
            res+=d1*getCount(d1,n);
            if(d1!=d2)
            res+=d2*getCount(d2,n);
        }
    }
    return res;
   // cout<<res<<"\n";
}
int main()
{
    int t;
    init();
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<gcdSum(n)<<"\n";
    }
    
    return 0;
}
