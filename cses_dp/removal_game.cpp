#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (int) 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    ll a[n];
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+= a[i];
    }
    //best[l][r] = score1 - score2 when only [l,r] interval is considered
    vector<vector<ll>> best(n, vector<ll>(n));
    //best[l][r] = max(a[l]-best[l+1][r], a[r]-best[l][r-1])
    for(int l = n-1; l>=0; l--){
        for(int r = l; r<n; r++){
            if(l==r) best[l][r] = a[l];
            else best[l][r] = max(a[l]-best[l+1][r], a[r]-best[l][r-1]);
        }
    }
    cout<<(sum+best[0][n-1])/2<<endl;
    return 0;
}