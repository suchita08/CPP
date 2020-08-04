#include<bits/stdc++.h>
using namespace std;
#define n1 100005
vector<int> arr[n1];
bool vis[n1];
void dfs(int v)
{
    vis[v]=1;
    cout<<v<<" ";
    //for Each loop can also be used 
    //example for(int child:ar[v)){if vis[child]==0 dfs(child);}
    for(int i=0;i<arr[v].size();i++)
    {
        
        int child=arr[v][i];
        //if the node is marked ,then visit that node 
        if(vis[child]==0)
        {
            dfs(child);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        //this while loop is for adjacency list 
        while(m--)
        {   int a,b;
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        dfs(1);
        cout<<"\n";
        //unmark all the node of the vistited array in case that they are marked
        //in the previous test case
        //clear the adjacency list as well (as for each test case the adjacency list will be different)
        for(int j=1;j<=n;j++){
            vis[j]=0;
            arr[j].clear();
        }
    }
    return 0;
}
