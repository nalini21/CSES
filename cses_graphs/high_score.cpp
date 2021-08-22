// Bellman's Ford Algo
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF = 1e17;
const ll NINF = INF*(-1);
 
struct edge{
	ll u, v, w;
};
 
ll n, m;	
vector<edge> edges;
vector<ll> dist;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>> m;
	dist.resize(n+1);
	edges.resize(m);
	for(ll i = 0; i < m; ++i){
		struct edge inp;
		cin>>inp.u>>inp.v>>inp.w;
		inp.w*=-1; 
		edges[i]=inp;
	}
	for(ll i = 2; i <= n; ++i)
		dist[i] = INF;
	
    for(ll i = 1; i < n; ++i){
        for(auto e: edges){
            ll u = e.u;
            ll v = e.v;
            ll d = e.w;
            if(dist[u] == INF) continue;
            dist[v] = min(dist[v], d+dist[u]);
            dist[v] = max(dist[v], NINF);
        }      
    } // n relaxations
    for(ll i = 1; i < n; ++i){
		for(auto e: edges){
			ll u = e.u;
			ll v = e.v;
			ll d = e.w;
			if(dist[u] == INF) continue;
			dist[v] = max(dist[v], NINF);
			if(dist[u]+d < dist[v])
				dist[v] = NINF;
		}
	}
	if(dist[n] == NINF) cout<<-1<< endl;
	else cout<<dist[n]*(-1)<< endl;
    return 0;
}