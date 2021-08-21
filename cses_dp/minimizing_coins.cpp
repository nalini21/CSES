#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long 
using vi = vector<int>;

//solve(x) = min(for_all_ci_in_coins(solve(x-ci)+1)) = min number of coins required to get a sum x

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin>>n>>x;
    vi coins(n), dp(x+1, 1e9);
    for(int i=0;i<n;i++) cin>>coins[i];
    dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(int c:coins){
            if(i-c>=0){
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
    }
    if(dp[x]!=1e9) cout<<dp[x]<<endl;
    else cout<<"-1"<<endl;
    return 0;
}