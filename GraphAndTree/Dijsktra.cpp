#include <bits/stdc++.h> 
using namespace std; 
#define INF 1000000000
//program to find the shortest distance between each nodes using DIjsktra's algorithm.
//adj[] is vector pair to insert the node and its weight.
vector<pair<int,int>>adj[1001];

int main() 
{ 
	int n,e;
	cin>>n>>e;
	int a,b,w;
	for(int i=0;i<e;i++)
	{
	    cin>>a>>b>>w;
	    adj[a].push_back({b,w});
	    adj[b].push_back({a,w});
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int> > >pq;
	vector<int>dist(n+1,INF);
	pq.push({0,1});
	dist[1]=0;
	while(!pq.empty())
	{
	    int curr_dist=pq.top().first;
	    int curr=pq.top().second;
	    pq.pop();
	    for(pair<int,int>edge:adj[curr])
	    {
	       if(curr_dist+edge.second<=dist[edge.first])
	        {
	           dist[edge.first]=curr_dist+edge.second;
	           pq.push({dist[edge.first],edge.first});
	        }
	    }
	    
	}
	for(int i=1;i<=n;i++)
	{
	    cout<<dist[i]<<" ";
	}
	return 0; 
} 
