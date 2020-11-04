#include <bits/stdc++.h>
using namespace std;
//Program :: find the distance of nearest 1 in the matrix for each cell. 
//logic :: bfs (first store all the cells that contains 1 in the cell ,then Run a loop till the size of the queue is greater than 0 then extract the front node of the queue and remove it and insert all its adjacent and unmarked elements. Update the minimum distance as distance of current node +1 and insert the element in the queue.)
int dist[505][505];
int n,m;
int mat[505][505];
int vis[505][505];
queue<pair<int,int>>q;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
bool isValid(int a,int b)
{
    return (a>=0 && b>=0 && a<n && b<m && vis[a][b]==0);
}
int main()
{
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    cin>>n>>m;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>mat[i][j];
	            if(mat[i][j]==1)
	            {
	                vis[i][j]=1;
	                dist[i][j]=0;
	                q.push({i,j});
	            }
	            else
	            {
	                vis[i][j]=0;
	                dist[i][j]=-1;
	            }
	        }
	    }
	    while(!q.empty())
	    {
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        for(int i=0;i<4;i++)
	        {
	            int X=x+dx[i];
	            int Y=y+dy[i];
	            if(isValid(X,Y) && mat[X][Y]==0)
	            {
	                dist[X][Y]=dist[x][y]+1;
	                q.push({X,Y});
	                vis[X][Y]=1;
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cout<<dist[i][j]<<" ";
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}