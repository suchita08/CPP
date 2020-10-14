#include<bits/stdc++.h>
using namespace std;


void counting_sort(int *arr,int n)
{
    int max=*max_element(arr,arr+n);
    int min=*min_element(arr,arr+n);
    int range=max-min+1;
    int count[range];
    int output[n];
    for(int i=0;i<range;i++) count[i]=0;
    for (int i = 0; i < n; i++) 
        count[arr[i] - min]++; 
  
    for (int i = 1; i <range; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = n - 1; i >= 0; i--) { 
        output[count[arr[i] - min] - 1] = arr[i]; 
        count[arr[i] - min]--; 
    } 
  
    for (int i = 0; i < n; i++) 
        arr[i] = output[i]; 
    
    
}
int main()
{
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
            cin>>arr[i];
    counting_sort(arr,n);
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
    return 0;
}
