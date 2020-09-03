#include<bits/stdc++.h>
using namespace std;
int N;
char arr[31][31];
bool vis[31][31];
int dist[31][31];
//DFS on 2D Grid 
//isValid() is a function which check for the avalibilty of cells 
bool isValid(int x , int y)
{
	if(x < 1 || x > N || y < 1 || y > N)
	return false;
    //if the cell is tree or visited then it will be non-valid cell 
	if(vis[x][y] == true || arr[x][y]=='T')
	return false;
 
	return true;
}
 
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
//check for up,left,right,down cell ,if it is valid then call the dfs 

void bfs(int x ,int y)
{
    queue<pair<int,int>>q;
	vis[x][y] = 1;
	dist[x][y]=0;
	q.push({x,y});
	while(!q.empty())
	{
	    int currX=q.front().first;
	    int currY=q.front().second;
	    q.pop();
	    //considering the sides only as edges . 
	    for(int i=0;i<4;i++)
	    {
	        if(isValid(dx[i]+currX,dy[i]+currY))
	        {
	            int newX=dx[i]+currX;
	            int newY=dy[i]+currY;
	            dist[newX][newY]=dist[currX][currY]+1;
	            vis[newX][newY]=1;
	            q.push({newX,newY});
	        }
	    }
	}
}
 
 
int main()
{
	cin>>N;
	int srcx,srcy,endx,endy;
	for(int i=1;i<=N;i++)
	{
	    for(int j=1;j<=N;j++)
	    {
	        cin>>arr[i][j];
	        //Initializing the starting and ending points.
	        if(arr[i][j]=='S') srcx=i,srcy=j;
	        if(arr[i][j]=='E') endx=i,endy=j;
	        
	    }
	}
	bfs(srcx,srcy);
	cout<<dist[endx][endy]<<"\n";
}