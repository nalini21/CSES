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
using vpii = vector<pair<ll, ll>>;
using vvb = vector<vector<bool>>;
using vpii = vector<pair<ll,ll>>;
using pqpii = priority_queue<pii, vector<pii>, greater<pii>>;

const ll MAXD = 1e17;
ll n, m;

int main()
{
	cin>>n>>m;
	//in[i] contains flights from city i
	//out[i] contains flights to city i
	vpii in[100001], out[100001];
	while(m--){
		ll a, b, c;
		cin>>a>>b>>c;
		out[a].push_back({b, c});
		in[b].push_back({a, c});
	}
	priority_queue<pair<ll, ll>> q; //(-price, city)
	vb visited(100001, false);

	//find the price to go from city 1 to all other cities
	vi dist1(100001, MAXD);
	dist1[1] = 0;
	q.push({0, 1});
	while (!q.empty()){
		ll u = q.top().second; 
		q.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (auto e : out[u]){
			ll v = e.first, w = e.second;
			if (dist1[u] + w < dist1[v]){
				dist1[v] = dist1[u] + w;
				q.push({-dist1[v], v});
			}
		}
	}

	//find the price to go from each city to city n
	vi distn(100001, MAXD);
	for(ll i=0;i<n+1;i++) visited[i] = false;
	distn[n]=0;
	q.push({0, n});
	while (!q.empty()){
		ll u = q.top().second;
		q.pop();
		if (visited[u]) continue;
		visited[u]=true;
		for (auto e:in[u]){
			ll v=e.first, w=e.second;
			if (distn[u]+w<distn[v]){
				distn[v]=distn[u] + w;
				q.push({-distn[v], v});
			}
		}
	}

	//take the minimum cost after using the coupon over all pairs of cities
	ll cost = dist1[n];
	for (ll u=1;u<=n; u++){
		for (auto node : out[u]){
			ll v = node.first;
			ll w = node.second;
			cost=min(cost,dist1[u]+distn[v]+w/2);
		}
	}
	cout<<cost<<endl;
	return 0;
}
