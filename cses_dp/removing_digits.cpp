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
    int n; cin>>n;
    vi dp(n+1, 1e9);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(char c: to_string(i)){
            dp[i] = min(dp[i], dp[i-(c-'0')]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}