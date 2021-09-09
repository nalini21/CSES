//succesor path modifies : to return the minimum no of transportation required to reach node b from node a.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MAXN = 2*1e5 + 5;
vector<vector<ll>> succ(32, vector<ll>(MAXN));
vector<ll> visited(MAXN, false);
vector<ll> len(MAXN, 0);

void dfs(int u){
    visited[u] = true;
    int v = succ[0][u];
    if (!visited[v]) dfs(v);
    len[u] = len[v]+1;
}

int lift(int x, int d){
    if (d <= 0) return x;
    int i = 0;
    while (d){
        if (d&1) x = succ[i][x];
        d >>= 1;
        i++;
    }
    return x;
}
   
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, q;
    cin>>n>>q;
    for(ll j=1;j<=n;j++) cin>>succ[0][j];
    for(ll i=1;i<32;i++)
        for(ll j=1;j<=n;j++)
            succ[i][j] = succ[i-1][succ[i-1][j]];
    
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) dfs(i);

    while(q--){
        ll x, y; cin>>x>>y;
        int z = lift(x, len[x]);
        if(lift(x, len[x]-len[y]) == y) 
            cout<<len[x]-len[y]<<endl;
        else if(lift(z, len[z]-len[y]) == y)
            cout<<len[x]+len[z]-len[y]<<endl;
        else cout<<-1<<endl;
    }
     return 0;
}