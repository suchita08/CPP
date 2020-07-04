#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

//function to check for the prime
//time complexity:0(sqrt(n))

bool prime_check(ll n)
{
    ll i,flag=0;
    if(n==1)
    return false;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll n;
        cin>>n;
        cout<<prime_check(n);
    return 0;

}
