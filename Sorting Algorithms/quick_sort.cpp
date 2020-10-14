#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition (int arr[], int start, int end)  
{  
    int pivot = arr[end];   
    int i = (start - 1);  
  
    for (int j =start; j <=end - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[end]);  
    return (i + 1);  
}  
void quick_sort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int p = partition(arr, low, high);  
        quick_sort(arr, low, p - 1);  
        quick_sort(arr, p + 1, high);  
    }  
}  
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quick_sort(a,0,n-1);
    cout<<"Array after sorting"<<"\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    
    return 0;
}