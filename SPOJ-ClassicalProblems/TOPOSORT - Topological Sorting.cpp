#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i = 1; i <= n; i++)
#define vi vector<int>
vector<int>adj[10001];
vector<int>res;
int in[10001];
//topological sort for the Directed  Graph 
//Cyclic graph do not have topological sort 
bool Kahns(int n)
{
    //priority_queue is used for the lexigraphically smallest order.
	priority_queue<int,vi,greater<int> > pq;
	
	//look for all the node with indegree zero.
 
	REP(i , n) if(in[i] == 0) pq.push(i);
 
	while(!pq.empty())
	{
	    //pop the top element from the queue and remove all its edges by decreasing the indegree.
		int curr = pq.top();
		res.push_back(curr);
		pq.pop();
 
		for(int child : adj[curr])
		{
			in[child]--;
			if(in[child] == 0)
			pq.push(child);
		}
	}
 
	return res.size() == n;
}
int main()
{
    
    int n , x , y , m;
	cin>>n>>m;
 
	REP(i , m) cin>>x>>y , adj[x].push_back(y) , in[y]++;
 
	if(!Kahns(n))
	cout<<"Sandro fails.";
	else
	{
		for(int node : res)
		cout<<node<<" ";
	}
    return 0;
}