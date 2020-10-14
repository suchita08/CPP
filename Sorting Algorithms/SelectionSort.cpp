#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
    
}
void selection_sort(int a[],int n)
{
    int i,j,min_id=0;
    for(i=0;i<(n-1);i++)
    {
        min_id=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min_id]>a[j])
            {
                min_id=j;
            }
        }
        swap(&a[i],&a[min_id]);
    }
}
int main()
{
    int n; 
    cin>>n;
    int arr[n],i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    selection_sort(arr,n);
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
    cout<<"\n";
}