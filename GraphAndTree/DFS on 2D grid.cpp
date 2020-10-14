#include<bits/stdc++.h>
using namespace std;
int N , M;
bool vis[1001][1001];
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

void dfs(int x ,int y)
{
	vis[x][y] = 1;
	cout<<x<<" "<<y<<"\n";
 
	for(int i=1;i<=4;i++)
	if(isValid(x + dx[i] , y + dy[i]))
	dfs(x + dx[i] , y + dy[i]);
}
 
 
int main()
{
	cin>>N>>M;
	dfs(1,1);
}