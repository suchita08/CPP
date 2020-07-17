#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long int
#define mod 1000000009
//Euler totient Function give us the number of co-prime upto n 
//Time Complexity:O(sqrt(n)
//Formula for ETF(n)=n*((p1-1)/p1)*((p2-1)/p2)*((p3-1)/p3)*......*((pk-1)/pk) if k is the total number of divisors.
int ETF(int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res=res/(i);
            res=res*(i-1);
            while(n%i==0)
            n/=i;
        }
    }
    //To handle the case if number n is prime itself 
    if(n>1)
    {
        res=res/n;res*=(n-1);
    }
    return res;
}
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<"Euler Totient Function"<<" "<<ETF(n)<<"\n";
    }
    
    return 0;
}
