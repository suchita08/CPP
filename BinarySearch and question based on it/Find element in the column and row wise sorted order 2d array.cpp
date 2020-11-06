#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//program to search for the element in the 2d array which is row-wise and column-wise sorted.
//Time Complexity:: O(n+m) where n is no. of rows and m is no. of columns.
// logic ::  https://youtu.be/VS0BcOiKaGI

 int arr[35][35];
 int n,m;
 
vector<int> search_for_key(int i ,int j,int key)
{
    vector<int>ans(2);
    ans[0]=-1;
    ans[1]=-1;
    while(i>=0 && i<n && j>=0 && j<m)
    {
        if(arr[i][j]==key) 
        {
            ans[0]=i;
            ans[1]=j;
            return ans;
        }
        else if(arr[i][j]>key) j--;
        else i++;
        
    }
    return ans;
    
}

int main()
{
    
    
        fast;
        int t;
        cin>>t;
        while(t--)
        {
            cin>>n>>m;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    cin>>arr[i][j];
            } 
            int ele;
            cin>>ele;
            vector<int>v;
            v=search_for_key(0,m-1,ele);
    	    cout<<v[0]<<" "<<v[1]<<"\n";
        }
	return 0;
}