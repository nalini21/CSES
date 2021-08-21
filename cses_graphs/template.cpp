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

ll n, m;
vvi adj_list;
vb visited;

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
    }

    return 0;
}
