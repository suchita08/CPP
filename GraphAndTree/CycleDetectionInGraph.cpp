#include<bits/stdc++.h>
using namespace std;
int vis[ 2001];
vector<int>arr[ 2001];
//Back Edge:It is an edge (u, v) such that v is ancestor of edge u but not part of DFS tree.a Back Edge is an edge that connects a vertex to a vertex that is discovered before it's parent.(Any edge that connects a node to its ancestor which is not its parent).
//presence of back-edge indicates cycle in the graph.
//dfs for checking if it there is a back edge or not  
//here we have passed the node and parent as parameter 
//intially the parent node will be -1 
//after running the dfs ,the current node will become the parent node.
bool dfs(int node,int par)
{
    vis[node]=1;
    for(int child:arr[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child,node)==true)
            {
                return true;
            }
        }
        else
        if(child!=par)
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    int k=1 ;
    while(k<=t)
    {
        int n,m;
        cin>>n>>m;
        //clear the adjacency list and visited graph for each test case
        for(int i=1;i<=n;i++)
        {
            arr[i].clear();
            vis[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        if(dfs(1,-1)){cout<<"Cycle is detected"<<"\n";}
        else{cout<<"No cycle is detected"<<"\n";}
        k+=1 ;
    }
    return 0;
}
