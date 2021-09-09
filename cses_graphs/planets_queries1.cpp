//succesor path 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MAXN = 2*1e5 + 5;
vector<vector<ll>> succ(32, vector<ll>(MAXN));

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, q;
    cin>>n>>q;
    for(ll j=1;j<=n;j++) cin>>succ[0][j];
    for(ll i=1;i<32;i++)
        for(ll j=1;j<=n;j++)
            succ[i][j] = succ[i-1][succ[i-1][j]];
    while(q--){
        ll x, k; cin>>x>>k;
        ll i=0;
        while(k){
            if(k&1) 
                x = succ[i][x];
            k>>=1;
            i++;
        }
        cout<<x<<endl;
    }
     return 0;
}