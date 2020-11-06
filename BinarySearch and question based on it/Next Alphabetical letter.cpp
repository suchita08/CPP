#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
int n;
char arr[34];
//Program :: Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
// logic :: similar to the ceil of an element of sorted array.


int modified_binary_search(int start,int end,char x)
{
    char res=arr[0];
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x) start=mid+1;
        else if(arr[mid]>x )
        {
            res=arr[mid];
            end=mid-1;
        }
            
        else if(arr[mid]<x)
        {
            start=mid+1;
        }
        
    }
    return res;
}
int main()
{
    
    fast;
	int t;
	cin>>t;
	while(t--)
	{
	   
	    cin>>n;
	    
	    for(int i=0;i<n;i++) cin>>arr[i];
	    char ele;
	    cin>>ele;
	    
	    
	    char a1=modified_binary_search(0,n-1,ele);
	    
	    cout<<a1<<"\n";
	    
	}
	return 0;
}