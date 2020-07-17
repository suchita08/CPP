#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long int

//the modulomultiplicative inverse of 'a' under modulo m is given by a^(mod-2).
int power(int x, int y,int mod)

{
    int res=1;
    while(y>0)
    {
        if(y%2)
        {
            res=(res*x)%mod;
            y--;
        }
        else
        {
            x=(x*x)%mod;
            y=y/2;
        }
    }
    return res;
}
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int a,m;
        cin>>a>>m;
        cout<<"The multiplicative inverse of a under modulo m "<<power(a,m-2,m)<<"\n";
    }
    return 0;
}
