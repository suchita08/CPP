#include <bits/stdc++.h>
using namespace std;
//Problem :: Given a directed graph, find out if a vertex v is reachable from               another vertex u for all vertex pairs (u, v) in the given graph.             Here reachable mean that there is a path from vertex u to v. The             reach-ability matrix is called transitive closure of a graph.
//logic ::  Create a matrix tc[V][V] that would finally have transitive closure         of given graph. Initialize all entries of a[][] as 0.
 //           Call DFS for every node of graph to mark reachable vertices in a[][]. In recursive calls to DFS, we don’t call DFS for an adjacent vertex if it is already marked as reachable in a[][].
 
 
int vis[105];
int n;
int mat[105][105];
vector<int>adj[105];
void dfs(int s,int d,int a[101][101])
{
    a[s][d] = 1;
    for(auto x : adj[d]) ///go through the d
    {
        if(a[s][x] == false)
            dfs(s,x,a);
    }
}
int main()
{
    
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            int x;
                cin>>x;
                if(x == 1)
                adj[i].push_back(j);
	        }
	    }
	    //for(int i=0;i<n;i++) vis[i]=0;
	     int a[101][101] = {{0}};
	    for(int i=0;i<n;i++)
	    {
	        //if(vis[i]==0)
	        dfs(i,i,a);
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cout<<a[i][j]<<" ";
	        }
	    }
	    for(int i=0;i<n;i++) adj[i].clear();
	    cout<<"\n";
	    
	}
	return 0;
}