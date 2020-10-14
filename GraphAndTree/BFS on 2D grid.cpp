#include<bits/stdc++.h>
using namespace std;
int N , M;
bool vis[1001][1001];
int dist[1001][1001];
//DFS on 2D Grid 
//isValid() is a function which check for the avalibilty of cells 
bool isValid(int x , int y)
{
	if(x < 1 || x > N || y < 1 || y > M)
	return false;
 
	if(vis[x][y] == true)
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
 
	for(int i=1;i<=N;i++)
	{
	    for(int j=1;j<=M;j++)
	    cout<<dist[i][j]<<" ";
	    cout<<endl;
	}
}
 
 
int main()
{
	cin>>N>>M;
	bfs(1,1);
}