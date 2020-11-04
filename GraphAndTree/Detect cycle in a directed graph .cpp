#include <bits/stdc++.h>
using namespace std;
//Program :: find the cycle in the directed graph.
//logic :: topological sort is possible for only Directed Acyclic Graph(DAG),so check if the size is less than the number of nodes ,then it means topplogical sort is not possible ,hence it contains the cycle.
bool top_sort(int V,vector<int>adj[])
{
    
    int size=0;
    int in[V]={0};
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            in[adj[i][j]]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(in[i]==0) 
        q.push(i);
    }
    while(!q.empty())
    {
        int curr=q.front();
        size++;
        //res.push_back(curr);
        q.pop();
        for(int child:adj[curr])
        {
            in[child]--;
            if(in[child]==0) 
                q.push(child);
        }
    }
    if(size<V) return true;
    else return false;
}
int main()
{
	//code
	int t,n,m;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    vector<int>adj[n];
	    for(int i=0;i<m;i++)
	    {
	        int a,b;
	        cin>>a>>b;
	        adj[a].push_back(b);
	    }
	     bool FLAG=top_sort(n,adj);
            cout<< FLAG<<"\n";
	    //cout<<"\n";
	}
	return 0;
}