#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int start,int middle,int end)
{
    int i,j,k;
    int n1=middle-start+1;
    int n2=end-middle;
    int L[n1],R[n2];
    for (i = 0; i < n1; i++) 
        L[i] = arr[start + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[middle + 1 + j]; 
    i=j=0; k=start;
    while(i<n1 && j<n2)
    {
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    }
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}
void merge_sort(int arr[],int start,int end)
{
    if(start<end)
    {
        int middle=(start+(end-1))/2;
        merge_sort(arr,start,middle);
        merge_sort(arr,middle+1,end);
        merge(arr,start,middle,end);
        
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    merge_sort(a,0,n-1);
    cout<<"Array after merge sorting"<<"\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    
    return 0;
}