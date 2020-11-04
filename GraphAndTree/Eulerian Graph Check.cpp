#include <bits/stdc++.h> 
using namespace std; 
#define INF 1000000000
//program to check for the Euler path and euler Circuit in the undirected graph.
//If the graph is both Euler Path and Euler Circuit then it is called Eulerian.
// if neither euler path nor euler circuit --> return 0 
// only Euler path --> return 1 
//both Euler path and euler ciruit -->return 2
vector<int>adj[1001];
int n;
bool visited[1001];
void dfs(int node)
{
    visited[node]=1;
    for(int child:adj[node])
    {
        if(visited[child]==0)
            dfs(child);
    }
}
//check if all the vertices with non-zero degree is connected or not.
bool isConnected()
{
    int i;
    for(int i=0;i<n;i++)
        visited[i]=0;
    //Find a vertex with non-zero degree.
    for(int i=0;i<n;i++)
        if(adj[i].size()!=0)
            break;
    //If there is no edge then it is eulerian.
    if(i==n) return true;
    //Start DFS traversal from a vertex with non-zero degree
    dfs(i);
    // Check if all non-zero degree vertices are visited
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && adj[i].size()>0) return false;
    }
    return true;
}
int isEulerian()
{
    //If any of the vertices with non-zero degree is not connected,then it can be neither Euler path nor Euler Circuit.
    if(!isConnected) return 0;
    int odd=0;
    for(int i=0;i<n;i++)
    {
        //count the number of the vertices with odd degree
        if(adj[i].size()&1) odd++;
    }
    if(odd>2) return 0;
    //if the odd degree vertices is two then it is Euler Path ,if it is zero then it is Euler Circuit.
    //Note that odd count can never be 1 for undirected graph 
    return (odd)? 1:2 ;
    
    
}
int main() 
{ 
	int e;
	cin>>n>>e;
	int a,b,w;
	for(int i=0;i<e;i++)
	{
	    cin>>a>>b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	cout<<isEulerian();
	return 0; 
} 
