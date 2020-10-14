#include<bits/stdc++.h>
using namespace std;
void bucket_sort(float arr[],int size)
{
    vector<float>b[size];
    for(int i=0;i<size;i++)
    {
        int ind=arr[i]*size;
        b[ind].push_back(arr[i]);
    }
    for(int i=0;i<size;i++) sort(b[i].begin(),b[i].end());
    int index=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<b[i].size();j++)
            arr[index++]=b[i][j];
    }
}
int main()
{
    
    int n;
    cin>>n;
    float arr[n];
    for(int i=0;i<n;i++)
            cin>>arr[i];
    bucket_sort(arr,n);
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
    return 0;
}
