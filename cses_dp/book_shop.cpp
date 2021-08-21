#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c;
    cin>>n>>c;
    int w[n], v[n];
    vector<vector<int>> dp(n+1, vector<int>(c+1, 0));
    
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>v[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(w[i-1]-j<=0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+v[i-1]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][c]<<endl;
    return 0;
}