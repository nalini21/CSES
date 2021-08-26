//implementation of topological sort using bfs, dp approach used to calculate total no of paths from node 1 to some node i
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
using vi = vector<ll>;
const ll MOD = (ll) 1e9+7;

vi edge[100001], backedge[100001];
ll paths[100001], indegree[100001];
ll n,m,cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
	for(ll i=0;i<=n;i++){
		indegree[i] = 0;
        paths[i] = 0;
	}
    paths[1] = 1;
    while(m--){
        ll x, y; cin>>x>>y;
        edge[x].pb(y);
        backedge[y].pb(x);
        indegree[y]++;
    }
    queue<ll> q;
    for(ll i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int next : edge[node]){
            indegree[next]--;
            if(indegree[next]==0) q.push(next);
        }
        for(int prev : backedge[node]){
            paths[node] = (paths[node]+paths[prev])%MOD;
        }
    }
    cout<<paths[n]<<endl;
}

