#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string x,y;
        cin>>x;
        cin>>y;
        int n=x.length();
        int m=y.length();
        int dp[n+1][m+1],i,j;
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(x[i-1]==y[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<m+1;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        i=n;j=m;
        string res={};
        while(i>0 && j>0)
        {
            if(x[i-1]==y[j-1])
            {
                res=x[i-1]+res;
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                    i--;
                else
                    j--;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}