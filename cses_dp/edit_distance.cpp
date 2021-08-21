#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    int dp[n+1][m+1];
    dp[0][0] = 0;
    for(int i=1;i<=n;i++) dp[i][0] = i;
    for(int i=1;i<=m;i++) dp[0][i] = i;    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int cost = 0;
            if(a[i-1]!=b[j-1]) cost=1;
            dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+cost));
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}