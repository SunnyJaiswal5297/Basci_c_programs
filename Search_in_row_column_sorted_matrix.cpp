#include <bits/stdc++.h>
using namespace std;
#define SIZE 801

int search( int n,int m, int x, int[SIZE][SIZE]);

int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    int n,m,x,i,j;
    cin>>n>>m;
    
    int mat[SIZE][SIZE];
    
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
          mat[i][j] = 0;
        cin>>mat[i][j];
      }
    }
    
    cin>>x;
    cout << search(n,m,x, mat) << endl;
  
  }
  return 0;
}

int search( int n,int m, int x, int mat[SIZE][SIZE])
{
    int row=0,col=m-1;
    while(row<n && col>=0)
    {
        if(mat[row][col]==x)
            return 1;
        if(mat[row][col]>x)
            col--;
        else
            row++;
    }
    return 0;
}