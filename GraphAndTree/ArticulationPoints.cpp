#include<bits/stdc++.h>
using namespace std;
vector<int>adj[30005];
int vis[30005],in[30005],low[30005];
int timer;
set<int>AP;
void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=timer++;
    int children=0;
    for(int child:adj[node])
    {
        if(child==par) continue;
        if(vis[child]==1)
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);
            children++;
            low[node]=min(low[node],low[child]);
            if(in[node]<=low[child] && par!=-1)
                AP.insert(node);
            
        }
    }
    if(par==-1 && children>1)
    AP.insert(node);
}
int main()
{
    int n,m,a,b;
    int t;
    cin>>t;
    // cin>>n>>m;
    // vector<int>adj[n+1];
    while(t--)
    {
         cin>>n>>m;
            for(int i=1;i<=n;i++)
            {
                vis[i]=0;
                adj[i].clear();
            }
            AP.clear();
            timer=1;
            for(int i=1;i<=m;i++)
            {
                cin>>a>>b;
                adj[a].push_back(b);
                adj[b].push_back(a);
                
            }
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==0)
                dfs(i,-1);
            }
            cout<<AP.size()<<"\n";
    }
    return 0;
} 