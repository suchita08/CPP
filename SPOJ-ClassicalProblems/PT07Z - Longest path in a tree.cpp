#include<bits/stdc++.h>
using namespace std;
int vis[ 10001],in[10001],out[10001];
vector<int>arr[10001];
#define mod 1000000007
int maxnode,maxd;
//longest path in a tree is equal to the diameter of the tree 
//for finding the diameter of the tree we need to run the dfs two times 
//first run the dfs from the root node and then find the farthest node from root then run the dfs from the farthest node from the root node 
void dfs(int node,int d)
{
    vis[node]=1;
    if(d>maxd)
    {
        maxd=d;
        maxnode=node;
    }
    for(int child:arr[node])
    {
        if(vis[child]==0)
        {
            dfs(child,d+1);
        }
    }
}
int main()
{
                int n;
                cin>>n;
                
                //clear the adjacency list and visited graph for each test case
                for(int i=1;i<=(n-1);i++)
                {
                    int a,b;
                    cin>>a>>b;
                    arr[a].push_back(b);
                    arr[b].push_back(a);
                }
                maxd=-1;
                dfs(1,0);
                 for(int i=1;i<=n;i++)
                {
                    //arr[i].clear();
                    vis[i]=0;
                }
                maxd=-1;
                dfs(maxnode,0);
            cout<<maxd<<"\n";
    return 0;
}
