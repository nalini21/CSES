#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (int) 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    int sum = n*(n+1)/2;
    if(sum%2!=0){
        cout<<0<<endl;
        return 0;
    }
    sum /= 2;
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            if(j-i>=0)
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-i])%MOD;
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n-1][sum]<<endl;
    return 0;
}