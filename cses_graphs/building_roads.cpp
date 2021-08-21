#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long int
using vi = vector<ll>;
using vb = vector<bool>;
using sti = stack<ll>;
using pii = pair<ll, ll>;
using vvi = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vpii = vector<pair<ll,ll>>;

ll n, m, cnt=0;
vvi adj_list;
vi roads;
vb visited;

void dfs(int node){
    visited[node] = true;
    for(int u: adj_list[node]){
        if(!visited[u]){
            visited[u] = true;
            dfs(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m;
    visited.resize(n+1);
    adj_list.resize(n+1);
    while(m--){
        ll x, y;
        cin>>x>>y;
        adj_list[x].pb(y);
        adj_list[y].pb(x);
    }
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
            roads.pb(i);
        }
    }
    ll ans = roads.size();
    cout<<ans-1<<endl;
    for(ll i=1;i<ans;i++){
        cout<<roads[i-1]<<" "<<roads[i]<<endl;
    }

    return 0;
}
