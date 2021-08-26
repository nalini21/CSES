#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long int
using vi = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vi>;

vector<ll> adj_list[100001];
bool flag[100001], visited[100001];
ll child[100001], cnt[100001];
//cnt[i] stores the max distance from node i to node n
//flag[i] denotes if we can reach node n from node i or not
//child[i] stores the child node of node i in the current longest path which includes node i.

void dfs(ll node){
	visited[node] = true;
	for(int u : adj_list[node]){
		if(!visited[u]) 
			dfs(u);
		flag[node]=flag[node] | flag[u];
		if((cnt[node]<cnt[u]+1) && (flag[u]==true)){
			cnt[node] = cnt[u]+1;
			child[node] = u;
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;cin>>n>>m;
	for(int i=0;i<=n;i++){
		visited[i]=false;
		flag[i]=false;
		cnt[i]=0;
	}
	flag[n]=true;
    while(m--){
        ll x, y; cin>>x>>y;
        adj_list[x].pb(y);
    }
    dfs(1);
	if(!flag[1]){cout<<"IMPOSSIBLE"<<endl; return 0;}
	cout<<cnt[1]+1<<endl;
	cout<<"1 ";
	ll temp = 1;
	while(child[temp]!=n){
		cout<<child[temp]<<" ";
		temp = child[temp];
	}
	cout<<n<<endl;
	return 0;  
}

