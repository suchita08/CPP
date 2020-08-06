#include<bits/stdc++.h>
using namespace std;
int vis[100001],in[100001],out[100001];
vector<int>arr[100001];
//in and out time concept 
//in will store the time when the node is entering in the dfs and out will store the time when the node is leaving the dfs.
//Program:Given two nodes ,find whether first node is the subtree of another node or not 
//Logic :For being a subtree :  1.)out[firstnode]>out[secondnode]  
//2.)in[firstnode]<in[secondnode]
int timer=1;
void dfs(int node)
{
    vis[node]=1;
    in[node]=timer++;
    for(int child:arr[node])
    {
        if(vis[child]==0)
        {
            dfs(child);
        }
    }
    out[node]=timer++;
}
int main()
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
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            int parent,child;
            cin>>parent>>child;
            //condition for the subtree 
            if(in[child]>in[parent] && out[child]<out[parent])
            cout<<"Yes"<<"\n";
            else
            cout<<"No"<<"\n";
        }
    return 0;
}
