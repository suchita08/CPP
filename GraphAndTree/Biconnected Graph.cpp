#include <bits/stdc++.h>
using namespace std;
int vis[105],low[105],in[105];
int timer=0;
vector<int>adj[105];
int n,e;
set<int>AP;
//program to check if the graph is biconneted or not 
//Graph will be biconneceted if:
//  1.)Graph is connected(i.e. chech if all the vertices are visited or not).
//  2.)There is not articulation point in graph.

//AP is a set which store the articulation points.
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
            if(in[node]<=low[child] && par!=-1) AP.insert(node);
        }
    }
    if(par==-1 && children>1) AP.insert(node);
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>e;
        for(int i=0;i<e;i++ )
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    dfs(0,-1);
    int temp=0;
    //Now check whether the given graph is connected or not. An undirected graph is connected if all vertices are reachable from any starting 
    // point (we have taken 0 as starting point)
     for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            temp++;
            break;
        }
    }
    if(temp==0 && AP.size()==0) cout<<"1"<<"\n";
    else cout<<"0"<<"\n";
    AP.clear();
	for(int i=0;i<n;i++)
	{
	    vis[i]=0;
	    in[i]=0;
	    low[i]=0;
	    adj[i].clear();
	    
	}
    }
	return 0;
}