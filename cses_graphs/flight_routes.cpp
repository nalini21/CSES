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
using vvi = vector<vi>;
using vvb = vector<vb>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

ll n, m, k;
vvpii g;
vvi dist; 
const ll INF = 1e17;
 
void dij(){
	priority_queue <pii,vector<pii>,greater<pii>> pq; 
	pq.push({0,1});
	while(!pq.empty()){
		ll u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();	
		if(dist[u][k-1] < d) continue;
		for(auto e: g[u]){
			ll v = e.first;
			ll c = e.second;
			if(dist[v][k-1] > c+d) {
				dist[v][k-1] = c+d;
				pq.push({dist[v][k-1], v});
				sort(dist[v].begin(), dist[v].end());
			}
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	g.resize(n+1);
	dist.resize(n+1);
	for(ll i=1;i<=n;i++){
		dist[i].resize(k);
		for(ll j = 0; j <k; ++j) dist[i][j] = INF;
	}
	dist[1][0] = 0;
	while(m--){
		ll u, v, w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	dij();
	for(ll i=0;i<k;i++)
		cout<<dist[n][i]<<" ";
	return 0;
}