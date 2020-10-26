#include<bits/stdc++.h>
using namespace std;
//Minimum Swaps required to sort the given array using Graph
//Time Complexity :: O(n*log(n))
//Logic :: ans = Σi = 1k(cycle_size – 1) ,where k is the number of cycles.
int minSwaps(int arr[], int n)
{
    // Create an array of 
    // pairs where first
    // element is array element 
    // and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
    // Sort the array by array 
    // element values to
    // get right position of 
    // every element as second
    // element of pair.
    sort(arrPos, arrPos + n);
 
    // To keep track of visited elements. 
    // Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);
 
    // Initialize result
    int ans = 0;
 
    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
 
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
 
        // Update answer by adding current cycle. 
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
 
    // Return result
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n],i,ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<minSwaps(arr,n)<<"\n";
    }
    return 0;
    
}