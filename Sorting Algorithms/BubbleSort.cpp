#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void bubble_sort(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
       for(int j=0;j<(n-i-1);j++)
       {
           if(a[j]>a[j+1])
            swap(&a[j],&a[j+1]);
       }
    }
}
int main()
{
    int n; 
    cin>>n;
    int arr[n],i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    bubble_sort(arr,n);
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
    cout<<"\n";
    return 0;
}