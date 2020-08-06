#include<bits/stdc++.h>
using namespace std;
vector<int> arr[100001];
int vis[100001] , subSize[100001];
//program: To calculate the size of the subtree
//dfs is called from the root node 
//logic:the size of the subtree of the parent will be equal to the size of the subtree of their children.
int dfs(int node)
{
	vis[node] = 1;
	int curr = 1;
 
	for(int child : arr[node])
	if(vis[child] == 0)
	{
		curr += dfs(child);
	}
 
	return subSize[node] = curr;
}
int main()
{
                int n,m;
                cin>>n>>m;
                
                //clear the adjacency list and visited graph for each test case
                for(int i=1;i<=m;i++)
                {
                    int a,b;
                    cin>>a>>b;
                    arr[a].push_back(b);
                    arr[b].push_back(a);
                }
                dfs(1);
                for(int j=1;j<=n;j++)
                cout<<subSize[j]<<" ";
                //cout<<subtree[x];
    return 0;
}
