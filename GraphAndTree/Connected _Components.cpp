#include<bits/stdc++.h>
using namespace std;
#define n 100005
int vis[n];
vector<int>arr[n];
//function for the depth first search 
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
    int t;
    cin>>t;
    while(t--)
    {
        int nodes,edges,a,b;
        cin>>nodes>>edges;
        while(edges--)
        {
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        //for loop to check the no. of connected components in the undirected graph 
        //Algo:All the nodes will be marked as visited for the particular connected components.
        int count=0;
        for(int j=1;j<=nodes;j++)
        {
            if(vis[j]==0)
            {
                dfs(j);
                count++;
            }
        }
        cout<<count<<"\n";
        for(int j=1;j<=nodes;j++)
        {
            vis[j]=0;
            arr[j].clear();
        }
    }
}
