// Bellman's Ford Algo
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF = 1e17;
const ll NINF = INF*(-1);
 
ll n, m;
struct edge{
    ll u, v, w;
};
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m;
	vector<ll> dist(n+1);
    vector<ll> parent(n+1, -1);
    vector<edge> edges(m); 

    for(ll i=0;i<m;i++){
        ll x, y, c;
        cin>>x>>y>>c;
        edges[i].u = x;
        edges[i].v = y;
        edges[i].w = c;
    }
    ll x=-1;
    for(ll i=0;i<n;i++){
        x = -1;
        for(auto e: edges){
            ll u = e.u;
            ll v = e.v;
            ll d = e.w;
            if(dist[u]+d<dist[v]){
                dist[v] = dist[u]+d;
                parent[v] = u;
                x=v;
            }
        }
    }
    if(x==-1) cout<<"NO"<<endl;
    else{
        for(ll i=0; i<n;i++)
            x = parent[x];
        vector<ll> cycle;
        for (ll v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        } 
        reverse(cycle.begin(), cycle.end());
        cout << "YES"<<endl;
        for (ll v : cycle)
            cout << v << ' ';
        cout<<endl;
    }
    return 0;
}
 