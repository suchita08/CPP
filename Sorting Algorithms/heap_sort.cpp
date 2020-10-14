#include<bits/stdc++.h>
using namespace std;
void maxheapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    while(l<n && arr[largest]<arr[l])
        largest=l;
    while(r<n && arr[largest]<arr[r])
            largest=r;
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        maxheapify(arr,n,largest);
    }
}
void heap_sort(int a[],int n)
{
    //to build the max heap using heapify
    for(int i=(n/2-1);i>=0;i--)
        maxheapify(a,n,i);
    //to delete the node from bottom .
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        maxheapify(a,i,0);
    }
}

int main()
{
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
            cin>>arr[i];
    heap_sort(arr,n);
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
    return 0;
}
