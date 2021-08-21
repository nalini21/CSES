#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (int) 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin>>n>>m;
    int x[n];
    for(int &i: x) cin>>i;
    vector<vector<int>> ways(n, vector<int>(m+1, 0));
    //ways[i][v] = number of ways to fill the array up to index i, if x[i] = v
    if(x[0] == 0){
        fill(ways[0].begin(), ways[0].end(), 1);
    }
    else ways[0][x[0]] = 1;
    for(int i=1;i<n;i++){
        if(x[i]==0){
            for(int j=1;j<=m;j++){
                for(int k : {j-1, j, j+1}){
                    if(k>=1 && k <=m){
                        (ways[i][j] += ways[i-1][k])%=MOD;
                    }
                }
            }
        }
        else{
           for(int k: {x[i]-1, x[i], x[i]+1}){
               if(k>=1 && k<=m){
                   (ways[i][x[i]] += ways[i-1][k])%=MOD;
               }
           } 
        }
        
    }
    int ans = 0;
    for(int i=1;i<=m;i++)
        (ans+=ways[n-1][i])%=MOD;
    cout<<ans<<endl;
    return 0;
}