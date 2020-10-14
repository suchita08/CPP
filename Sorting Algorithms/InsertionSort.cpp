#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int a[],int n)
{
    int i,j,key_element;
    for(i=0;i<n;i++)
    {
        j=i-1;
        key_element=a[i];
        while(j>=0 && a[j]>key_element)
        {
             a[j + 1] = a[j];  
            j = j - 1;  
        }
         a[j + 1] = key_element;  
    }
}
int main()
{
    int n; 
    cin>>n;
    int arr[n],i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    insertion_sort(arr,n);
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
    cout<<"\n";
    return 0;
}