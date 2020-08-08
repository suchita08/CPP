#include<bits/stdc++.h>
using namespace std;
//Problem :: SocialNetworkingGraph (hackerearth)
//here we have to find the number of nodes that are present at a given distance from the given source node 
//dist array is used to store the distance from the given source node 
//level array is used to store the number that are present at that level 
//bfs is used to find the level and distance from the given source node 
//(for bttr understanding just consider the test case and dry run the program)
vector<int> arr[1000001];
int vis[1000001] ,dist[1000001],level[1000001];
void bfs(int source)
{
    queue<int>q;
    vis[source]=1;
    q.push(source);
    dist[source]=0;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int child:arr[curr])
        {
            if(vis[child]==0)
            {
                dist[child]=dist[curr]+1;
                q.push(child);
                vis[child]=1;
                //Increment the level for each node for the distance 
                level[dist[child]]++;
            }
        }
        
    }
}
int main()
{      
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int m,src,d;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>src>>d;
        for(int i=0;i<=e;i++)
        {
            level[i]=0;
            vis[i]=0;
        }
        bfs(src);
        cout<<level[d]<<"\n";
    }
    return 0;
}
