#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (int) 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll dp[n+2][2];
        dp[n+1][0] = dp[n+1][1] = 1;
        for(int i=n;i>=2;i--){
            dp[i][0] = (dp[i+1][0] + dp[i+1][1]) % MOD + (dp[i+1][0]) + (2 * dp[i+1][0]) % MOD;
            dp[i][1] = (dp[i+1][0] + dp[i+1][1]) % MOD + (dp[i+1][1]);
        }
        cout<<(dp[2][0]+dp[2][1])%MOD<<endl;
    }
    return 0;
}