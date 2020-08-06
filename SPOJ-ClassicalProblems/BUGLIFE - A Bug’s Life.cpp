#include<bits/stdc++.h>
using namespace std;
int vis[ 2001],col[2001];
vector<int>arr[ 2001];
//dfs for checking if it possible to mark the color in the graph adjacently or not
bool dfs(int v,int c)
{
    vis[v]=1;
    col[v]=c;
    for(int child : arr[v])
    {
        if(vis[child]==0)
        {
            //xor is used to make the color reverse(i.e make it equal to 1 if it is 0 or vice-versa)
            if(dfs(child,c^1)==false)
            return false;
        }
        else 
        if(col[child]==col[v])
        return false;
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    int k=1 ;
    while(k<=t)
    {
        int n,m;
        cin>>n>>m;
        //clear the adjacency list and visited graph for each test case
        for(int i=1;i<=n;i++)
        {
            arr[i].clear();
            vis[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        bool flag=true;
        //remember that there can be more than one connected components for the given test case 
        //check for every connected components ,if any one of the connected components does not satisfy then bipartite is not possible.
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==0)
            {
                bool res=dfs(j,0);
                if(res==false)
                flag=false;
            }
        }
        cout<<"Scenario #"<<k<<":"<<"\n";
        if(flag) cout<<"No Suspicious bugs found!"<<"\n";
        else cout<<"Suspicious bugs found!"<<"\n";
        k+=1 ;
    }
    return 0;
}
