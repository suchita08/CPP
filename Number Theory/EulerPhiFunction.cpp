#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long int
#define mod 1000000009
int phi[1000001];
//Euler totient Function give us the number of co-prime upto n 
//Time Complexity:O(n*log((log(n))
//Formula for ETF(n)=n*((p1-1)/p1)*((p2-1)/p2)*((p3-1)/p3)*......*((pk-1)/pk) if k is the total number of divisors.
int init(int maxn)
{
    for(int i=1;i<=maxn;i++)
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
int main()
{
    
    init(1000000);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<"Euler Totient Function"<<" "<<phi[n]<<"\n";
    }
    
    return 0;
}
