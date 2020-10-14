#include<bits/stdc++.h>
using namespace std;


void counting_sort(int arr[],int n,int exp)
{
    int count[10]={0};
    int i, output[n];
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    
}
void radix_sort(int arr[],int size)
{
    int m=*max_element(arr,arr+size);
    for(int i=1;m/i>0;i*=10)
        counting_sort(arr,size,i);
}
int main()
{
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
            cin>>arr[i];
    radix_sort(arr,n);
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
    return 0;
}
