#include<bits/stdc++.h>
using namespace std;
//program to find the bridge of the given graph 
//Bridge:An edge in an undirected connected graph is a bridge iff removing it disconnects the graph. For a disconnected undirected graph, definition is similar, a bridge is an edge removing which increases number of disconnected components.
//the back edge can never be bridge so for bride check for only forward edge 
//here low is the array that stores the lowest ancestor of the node and in is the array that stores the time when the node is enter in graph 
vector<int> arr[101];
int vis[101] ,in[101],low[101];
int timer;
void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;
    for(int child:arr[node])
    {
        
        if(child==par)
        continue;
        else if (vis[child]==1)
        {
            //the edge is back edge 
            low[node]=min(low[node],in[child]);
        }
        else
        {
            //the edge is forward edge 
            dfs(child,node);
            //condition for the bridge 
            if(low[child]>low[node])
            cout<<node<<"-->"<<child<<"is a bridge"<<"\n";
            low[node]=min(low[child],low[node]);
            
        }
    }
}
int main()
{      
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1,-1);
    return 0;
}
