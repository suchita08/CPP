#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long int
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    vector<int>arr[n+1];
    //for(int i=1;i<=n;i++)
    //arr[i].clear();
    while(m--)
    {
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {   
        cout<<i<<" ";
        for(int j=0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
