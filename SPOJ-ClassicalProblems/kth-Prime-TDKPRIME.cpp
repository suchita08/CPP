#include<bits/stdc++.h>
using namespace std;
vector<int>v;
bool arr[87000008];
void sieve()
{
    int maxN=87000008;
    arr[0]=arr[1]=true;
    for(int i=2;i*i<=maxN;i++)
    {
        if(!arr[i])
        {
            for(int j=i*i;j<=maxN;j+=i)
            arr[j]=true;
        }
    }
     for(int i=2;i<=maxN;i++)
    {
        if(!arr[i])
        v.push_back(i);
    }
}
int main()
{
    long long int t;
    cin>>t;
    sieve();
    while(t--)
    {
    long long int n;
    cin>>n;
    cout<<v[n-1]<<"\n";
    }
    return 0;

}
