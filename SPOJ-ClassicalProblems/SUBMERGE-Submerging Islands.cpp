#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
int vis[10001],in[10001],low[10001];
int timer;
//AP is a set used to store the articulation points .
//Here,set is taken because while running the dfs the same node can be encountered more than once.
set<int>AP;
void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=timer++;
    //children is used to store the number of child a root node contains.
    int children=0;
    for(int child:adj[node])
    {
        
        if(child==par) continue;
        //if the edge is back-edge than update low[node]
        if(vis[child]==1)
        {
            low[node]=min(low[node],in[child]);
        }
        //if the child is not visited than call the dfs for that child and increment the children .
        
        else
        {
            dfs(child,node);
            children++;
            low[node]=min(low[node],low[child]);
            if(in[node]<=low[child] && par!=-1)
                AP.insert(node);
            
        }
    }
    //if the root have more than one child then it  will be articulation points
    if(par==-1 && children>1)
    AP.insert(node);
}
int main()
{
    int n,m,a,b;
    // cin>>n>>m;
    // vector<int>adj[n+1];
    while(1)
    {
         cin>>n>>m;
        if(n==0 && m==0)
        break;
        else
        {
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
    }
    return 0;
}