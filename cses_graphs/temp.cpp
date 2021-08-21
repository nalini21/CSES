//all source shortest path problem in undirected graph
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
ll n, m, q;
vvi adj_matrix;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m>>q;
    adj_matrix.resize(n+1);
    for(ll i=1;i<=n;i++) adj_matrix[i].resize(n+1);
    for(ll i=1;i<=n;i++)
        for(ll j=i+1;j<=n;j++)
            adj_matrix[i][j] =  adj_matrix[j][i] = MAXD;
    while(m--){
        ll x, y, w;
        cin>>x>>y>>w;
        adj_matrix[x][y] = adj_matrix[y][x] = min(adj_matrix[x][y], w);
    }
    //considering all the relaxations possible for each pair of vertices
    for(ll k=1;k<=n;k++)
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);

    while(q--){
        ll u, v;
        cin>>u>>v;
        if(adj_matrix[u][v]==MAXD) adj_matrix[u][v]= -1;
        cout<<adj_matrix[u][v]<<endl;
    }
    return 0;
}
