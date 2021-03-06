#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string a;
        cin>>a;
        int n=a.length();
        string b;
        for(int i=n-1;i>=0;i--)
            b=b+a[i];
        //cout<<a<<" "<<b<<endl; 
        int dp[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        int i=n,j=n;
        string res={};
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                res=a[i-1]+res;
                i--;
                j--;
            }
            else
            {
                if(dp[i][j-1]>dp[i-1][j])
                    j--;
                else
                    i--;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
/* string str=agbcba | abcbga
    output =5.
    */