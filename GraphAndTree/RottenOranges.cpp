#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
//explanation for the solution ::: https://youtu.be/XiUmnWXh-9E 
//link for the question ::   RottenOranges (gfg)
queue<pair<int,int>>q;
bool isValid(vector<vector<int> > &matrix, int R, int C,int a,int b)
{
    return (a >= 0 && b >= 0 && a < R && b < C && matrix[a][b]==1);
}
int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
    int t=0,fresh=0;
    
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(matrix[i][j]==2)
            {
                q.push({i,j});
            }
            else if(matrix[i][j]==1) fresh++;
        }
    }
    while(!q.empty())
    {
        int x,y;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            x=q.front().first;
            y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int X=x+dx[i];
                int Y=y+dy[i];
                if(isValid(matrix,R,C,X,Y))
                {
                    q.push({X,Y});
                    matrix[X][Y]=2;
                    fresh--;
                }
            }
        }
        if(!q.empty()) t++;
    }
    if(fresh==0) return t;
    else return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>mat(n);
        //int mat[n][m];
        for(int i=0;i<n;i++)
        {
            mat[i].resize(m);
            for(int j=0;j<m;j++)
            cin>>mat[i][j];
        }
        cout<<rotOranges(mat,n,m)<<"\n";
    }
    return 0;
    
}