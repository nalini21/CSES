#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long 
using vi = vector<int>;

const int MOD = (int) 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    char matrix[n][n];
    ll dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    if(matrix[0][0]!='.') {cout<<"0"<<endl;return 0;}
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        if(matrix[0][i]=='*') dp[0][i] = 0;
        else dp[0][i] = dp[0][i-1];
        if(matrix[i][0]=='*') dp[i][0] = 0;
        else dp[i][0] = dp[i-1][0];
    } 
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][j]!='*'){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
                dp[i][j]%=MOD;
            }
            else dp[i][j] = 0;
        }
    }    
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}