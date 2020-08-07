#include<bits/stdc++.h>
using namespace std;
vector<int> arr[100001];
vector<int>primes;
int vis[100001] ,dist[100001];
//Prime path(SPOJ)
//here we have build the adjacency list on byself 
//For adjacency list ,first find all the primes from 1000 to 999 store it in the vector .Then by using two loop we find the two primes which differ by only one digit and store it in the adjacency list.
//for shortest path we use breadth first search .
bool isPrime(int n)
{
    for(int j=2;j*j<=n;j++)
    {
        if(n%j==0)
        return false;
    }
    return true;
}
bool isValid(int a,int b)
{
    int count=0;
    while(a!=0)
    {
        if(a%10!=b%10)
        {
            count++;
        }
            a=a/10;
            b=b/10;
    }
    if(count==1) return true;
    else return false;
}
void buildgraph()
{
    for(int i=1000;i<=9999;i++)
    {
        if(isPrime(i))
        primes.push_back(i);
    }
    for(int i=0;i<primes.size();i++)
    {
        for(int j=i+1;j<primes.size();j++)
        {
            int a=primes[i];
            int b=primes[j];
            if(isValid(a,b))
            {
                arr[a].push_back(b);
                arr[b].push_back(a);
            }
        }
    }
}

void bfs(int source)
{
    queue<int>q;
    q.push(source);
	vis[source] = 1;
	dist[source]=0;
 
	while(!q.empty())
	{
	    int curr=q.front();
	    q.pop();
	    for(int child:arr[curr])
	    {
	        if(vis[child]==0)
	        {
	            q.push(child);
	            vis[child]=1;
	            dist[child]=dist[curr]+1;
	            
	        }
	    }
	}
}
int main()
{      
        int t;
        cin>>t;
        buildgraph();
        while(t--)
        {
                int a,b;
                cin>>a>>b;
                for(int i=1000;i<=9999;i++) dist[i]=-1,vis[i]=0;
                bfs(a);
                if(dist[b]==-1) cout<<"Impossible"<<"\n";
                else cout<<dist[b]<<"\n";
        }
    return 0;
}
