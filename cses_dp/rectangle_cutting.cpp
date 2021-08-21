#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9));
    for(int h=1;h<=a;h++){
        for(int w=1;w<=b;w++){
            if(h==w) dp[h][w] = 0;
            else{
                for(int i=1;i<h;i++)
                    dp[h][w] = min(dp[h][w], 1 + dp[h-i][w] + dp[i][w]);
                for(int i=1;i<w;i++)
                    dp[h][w] = min(dp[h][w], 1 + dp[h][w-i] + dp[h][i]);
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}