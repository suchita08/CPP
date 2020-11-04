#include <bits/stdc++.h>
using namespace std;
//Program to find the pair of nodes that are at a even distance.
//Logic:: 1.)  Choose any source node as root and perform dfs traversal and                 maintain the visited array for performing dfs and dist array to             calculate distance from the root.
//         2.)  now traverse the distaance array and keep count of even level               and odd level Calcluate total as  ((even_count * (even_count-1))                             + (odd_count * (odd_count-1))/2


void dfs(vector<int> graph[], int node, int dist[],  
                                    bool vis[], int c) 
{ 
    if (vis[node]) { 
        return; 
    } 
    vis[node] = true; 
  
  
    dist[node] = c; 
  
    for (int i = 0; i < graph[node].size(); i++) { 
       
        if (!vis[graph[node][i]]) { 
            dfs(graph, graph[node][i], dist, vis, c + 1); 
        } 
    } 
} 
  
int countOfNodes(vector<int> graph[], int n) 
{ 
    
    bool vis[n + 1] = { false }; 
    int dist[n + 1] = { 0 }; 
  
    dfs(graph, 1, dist, vis, 0); 
  
    int even = 0, odd = 0; 
    for (int i = 1; i <= n; i++) { 
        if (dist[i] % 2 == 0) { 
            even++; 
        } 
        else { 
            odd++; 
        } 
    } 
  
    int ans = ((even * (even - 1)) + (odd * (odd - 1))) / 2; 
  
    return ans; 
} 
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>adj[n+1];
        for(int i=1;i<(n);i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
             cout<< countOfNodes(adj,n)<<"\n";
    }
	//code
	return 0;
}