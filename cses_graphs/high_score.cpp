// Bellman's Ford Algo
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

const ll MAXD = 1e17;
ll n, m;
struct edge{
    int x, y, w;
};
vector<edge> edges;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m;
	vi dist(n+1, MAXD);
    edges.resize(n);
    dist[1] = 0;
    for(int i=0;i<m;i++){
        ll x, y, w;
        cin>>x>>y>>w;
        edges[i].x = x;
        edges[i].y = y;
        edges[i].w = -w;
    }
    int x=-1;
    for(int i=0;i<n;i++){
        x = -1;
        for(auto e: edges){
            int u = e.x;
            int v = e.y;
            int d = e.w;
            if(dist[u]==MAXD) continue;
            if(dist[v]>dist[u]+d){
                dist[v] = max<ll>(dist[u]+d, -1 * MAXD);
                x=1;
            }
        }
    }
    if(x==1) cout<<"-1"<<endl;
    else cout<< -1 * dist[n]<<endl;
    return 0;
}


