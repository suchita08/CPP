#include<bits/stdc++.h>
using namespace std;
vector<int> arr[100001];
int vis[10001] ,dist[10001];
//Monk and the Islands ::Hackerearth
//program for the bfs(Breadth First Search),similar to dfs only change is in dfs we use stack but in bfs we use queue .
//function to find the shortest distance from root node to last node using bfs 
//In bfs the travering is level order 
//we stored the source node in the queue firstly ,making it distance zero and the taking the all the node at the level one ,setting it distance by increment one ,similary we taverse we all the nodes level by level .
void bfs(int source)
{
    queue<int>q;
    q.push(source);
	vis[source] = 1;
	dist[source]=0;
 
	while(!q.empty())
	{
	    int curr=q.front();
	    q.pop();
	    for(int child:arr[curr])
	    {
	        if(vis[child]==0)
	        {
	            q.push(child);
	            vis[child]=1;
	            dist[child]=dist[curr]+1;
	            
	        }
	    }
	}
}
int main()
{       int t;
        cin>>t;
        while(t--)
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
                bfs(1);
               cout<<dist[n]<<"\n";
               for(int i=1;i<=n;i++)
               {
                   arr[i].clear();
                   vis[i]=0;
                   //dist[i]=0;
                }
        }
                //cout<<subtree[x];
    return 0;
}
