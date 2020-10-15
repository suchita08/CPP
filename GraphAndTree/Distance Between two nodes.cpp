#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
 
using namespace std;


//Program to find the distance between two given nodes.Here,we are using binary lifting concept .

vector<int> ar[1001];
const int maxN = 10;
int level[1001] , LCA[1001][maxN+1];
//dfs to find the level array and 2^0 parent of each nodes.
//n --> no. of nodes 
//maxN --> log(n)
//LCA[i][j] --> (2^j)th parent of i
void dfs(int node , int lvl , int par)
{
	level[node] = lvl;
	LCA[node][0] = par;
 
	for(int child : ar[node])
	if(child != par)
	{
		dfs(child , lvl+1 , node);
	}
}
 
//to find the LCA matrix.
//LCA means lowest common ancestor.
void init(int n)
{
	dfs(1 , 0 , -1);
 
	for(int i=1;i<=maxN;i++)
	{
		for(int j=1;j<=n;j++)
		if(LCA[j][i-1] != -1)
		{
			int par = LCA[j][i-1];
			LCA[j][i] = LCA[par][i-1];
		}
	}
}
 //to find the lca of the two given nodes.
int getLCA(int a , int b)
{
	if(level[b] < level[a]) swap(a , b);
 
	int d = level[b] - level[a];
 
	while(d > 0)
	{
		int i = log2(d);
		//cout<<b<<" ";
		b = LCA[b][i];
 
		d -= 1 << i;
	}
 
	if(a == b) return a;
 
	for(int i=maxN;i>=0;i--)
	if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
	{
		a = LCA[a][i] , b = LCA[b][i];
	}
 
	return LCA[a][0];
}
 
//to get the distance between two given nodes. 
int getDist(int a , int b)
{
	int lca = getLCA(a , b);
	return level[a] + level[b] - 2*level[lca];
}
 
int main()
{
	int n ,a , b , q;
 
	cin>>n;
 
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=maxN;j++)
		LCA[i][j] = -1;
	}
 
	for(int i=1;i<n;i++)
	cin>>a>>b , ar[a].pb(b) , ar[b].push_back(a);
 
	init(n);
 
	cin>>q;
 
	while(q--)
	{
		cin>>a>>b;
		cout<<getDist(a , b)<<endl;
	}
}