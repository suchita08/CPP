#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//program :: Given number of pages in n different books and m students. The         books are arranged in ascending order of number of pages. Every student     is assigned to read some consecutive books. The task is to assign books     in such a way that the maximum number of pages assigned to a student is     minimum.
//logic :: https://youtu.be/2JSQIhPcHQg
int arr[35];
int n;
bool isValid(int k,int max)
{
    int student=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>max)
        {
            student++;
            sum=arr[i];
        }
        if(student>k) return false;
    }
    return true;
}
int search_for_minimum_pages(int start ,int end,int k)
{
    int res=-1;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isValid(k,mid)) { res=mid;end=mid-1;}
        else start=mid+1;
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
            for(int i=0;i<n;i++)
            {
               
                    cin>>arr[i];
            } 
            int k;
            cin>>k;
            if(n<k) cout<<"-1"<<"\n";
            else
            {
                int low=*max_element(arr,arr+n);
                int high=accumulate(arr,arr+n,0);
                int ans=search_for_minimum_pages(low,high,k);
    	        cout<<ans<<"\n";
            }
        }
	return 0;
}