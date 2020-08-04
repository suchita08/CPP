#include<bits/stdc++.h>
using namespace std;
int vis[10001];
vector<int>arr[10001];
//This is a program for the tree check 
//For a given graph to be tree it satisfy the two condition 
//1. number of connected components must be one  2.. number of edges must be less than one times the no. of nodes (i.e. they must not contain any cycle)

void dfs(int v)
{
    vis[v]=1;
    for(int child : arr[v])
    {
        if(vis[child]==0)
        dfs(child);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            count++;
        }
    }
    //if the connected components is one and it does not contain any cycle then it is a tree 
    if(count==1 && m==(n-1))
    cout<<"YES"<<"\n";
    else
    cout<<"NO"<<"\n";
    return 0;
}
