#include<bits/stdc++.h>
using namespace std;
void shell_sort(int ar[],int n)
{
    int gap,i,j;
    for(gap=n/2;gap>=1;gap=gap/2)
    {
        for(j=gap;j<n;j++)
        {
            for(i=(j-gap);i>=0;i=i-gap)
            {
                if(ar[i+gap]>ar[i]) break;
                else swap(ar[i+gap],ar[i]);
            }
        }
    }
}
 
int main()
{
	int n;
	cin>>n;
	int i,a[n];
	for(i=0;i<n;i++) cin>>a[i];
	shell_sort(a,n);
	cout<<"Array after shell sorting:"<<"\n";
	for( i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}