#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long int
#define N 3
int I[3][3],arr[3],T[3][3];
#define REP(i,n) for(i=1;i<=n;i++)
//question based on recurence relation 
//function to perform the simple matrix multiplication
void mul(int A[3][3],int B[3][3],int dim)
{

    int res[dim+1][dim+1];
    int i,j,k;
    REP(i,dim)
    {

        REP(j,dim)
        {

            res[i][j]=0;
            REP(k,dim) res[i][j]+=(A[i][k]*B[k][j]);
        }

    }
    //Copy the value from the resultant matrix to initial matrix
    REP(i,dim)REP(j,dim) A[i][j]=res[i][j];

}
//function to perform the matrix multiplication n times

int getFib(int n)
{
    int i,j;
    if(n<=2)
    return arr[n];
    //Identity matrix
    I[1][1]=I[2][2]=1;
    I[1][2]=I[2][1]=0;
    //Transition Matrix
    T[1][1]=0;
    T[1][2]=T[2][1]=T[2][2]=1;
        //binary exponentiaion
        n=n-1;
        while(n)
        {

            if(n%2){
                mul(T,I,2);
                n--;
            }
            else{
                mul(T,T,2);
                n=n/2;
            }
        }
        int ans=((arr[1]*T[1][1])+(arr[2]*T[2][1]));
        return ans;
}

int main()
{
    int n;
    cin>>arr[1]>>arr[2]>>n;
    n++;
    cout<<getFib(n);
    return 0;
}
