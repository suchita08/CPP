#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
vector<int>res;
int in[10001];
//topological sort for the directed acyclic graph 
//Acyclic :No cylcle 
//Cyclic graph do not have topological sort 
void top_sort(int n)
{
    queue<int>q;
    //push that node that have zero indegree 
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        //take the front element from the queue and remove all its edge by decreasing the indegree of that graph 
        
        int curr=q.front();
        res.push_back(curr);
        q.pop();
        for(int node:adj[curr])
        {
            in[node]--;
            if(in[node]==0)
                q.push(node);
            
        }
    }
    cout<<"Topsort";
    for(int node:res)
        cout<<node<<" ";
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    top_sort(n);
    return 0;
}