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
using pqpii = priority_queue<pii, vpii, greater<pii>>;

const ll MAXD = 1e17;
ll n, m;
vvpii adj_list;
vi dist;

void dijkstra(){
    pqpii pq;
    pq.push({0, 1}); //(dist[node], node)
    while(!pq.empty()){
        ll u = pq.top().s;
        ll d = pq.top().f;
        pq.pop();
        if(dist[u]<d) continue;
        for(auto e: adj_list[u]){
            ll v = e.f;
            ll c = e.s;
            if(dist[v]<=d+c) continue;
            else{
                dist[v] = d+c;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m;
    dist.resize(n+1);
    fill(dist.begin(), dist.end(), MAXD);
    dist[1]=0;
    adj_list.resize(n+1);
    while(m--){
        ll x, y, w;
        cin>>x>>y>>w;
        adj_list[x].pb({y, w});
    }
    dijkstra();
    for(ll i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    return 0;
}
