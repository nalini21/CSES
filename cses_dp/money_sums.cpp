#include<bits/stdc++.h>
using namespace std;
const int MOD = (int) 1e9+7;
//given n coins with certain values.Task is to find all money sums we can create using these coins.
///1≤n≤100 
//1≤xi≤1000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int c[n]; for(int i=0;i<n;i++) cin>>c[i];
    int max_sum = n*1000;
    vector<vector<bool>> dp(n+1, vector<bool>(max_sum+1, false));
    //let dp[i][x] is true when it is possible to get a money sum x using first i coins
    //and if it possible then either we choose ith coin depends on whether dp[i-1][x-c[i]] is true or not
    dp[0][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=max_sum;j++){
            if(j-c[i-1]>=0 && dp[i-1][j-c[i-1]])
                dp[i][j] = true;
            else dp[i][j] = dp[i-1][j];
        }
    }
    vector<int> possible;
    for(int i=1;i<=max_sum;i++)
        if(dp[n][i]) possible.push_back(i);
    cout<<possible.size()<<endl;
    for(int i: possible) cout<<i<<" ";
    cout<<endl;
    return 0;
}