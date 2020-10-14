#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
 
using namespace std;
//edge is a structure used to store the nodes of the given edges along with their weights.
struct edge
{
    int a,b,w;
};

edge ar[100001];
int par[100001];
//comparator function for sorting the structure array according to their weight.Return true if a is placed before b else return false.
bool comp(edge a, edge b)
{
    if(a.w<b.w) return true;
    else return false;
}
//find the parent by using PATH BY COMPRESSION tehnique.
int find(int a)
{
    if(par[a]==-1) return a;
    else return par[a]=find(par[a]);
}
//union of two sets if they have different parent,i.e. including the edge in the minimum spanning tree.
void merge(int a,int b)
{
    par[a]=b;
}

int main()
{

	int  n, m,a,b,w,sum=0;
	cin>>n>>m;
	for(int j=0;j<n;j++) par[j]=-1;
	for(int i=0;i<m;i++)
	{
	   cin>>ar[i].a>>ar[i].b>>ar[i].w;
	   
	}
	sort(ar,ar+m,comp);
	for(int i=0;i<m;i++)
	{
	   int a=find(ar[i].a);
	   int b=find(ar[i].b);
	   cout<<ar[i].a<<" "<< a<<" ";
	    cout<<ar[i].b<<" "<< b<<" ";
	   cout<<endl;
	    
	    if(a!=b)  
	    {
	        sum+=ar[i].w;
	        merge(a,b);
	    }
	}
	cout<<sum<<"\n";
}
 