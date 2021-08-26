#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
bool vis[100001];
ll child[100001];
ll cnt[100001];
bool flag[100001];
vector<ll> v[100001];

void dfs(ll node){
    vis[node]=true;
    for(ll chil:v[node]){
        if(!vis[chil])
            dfs(chil);
        flag[node]|=flag[chil];
        if((cnt[node]<cnt[chil]+1)&&(flag[chil]==true)){
            cnt[node]=cnt[chil]+1;
            child[node]=chil;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,i;
    cin>>n>>m;
    ll x,y;
    for(i=0;i<m;i++){
        cin>>x>>y;
        v[x].pb(y);
    }
    flag[n]=true;
    dfs(1);
    if(!flag[1]) {cout<<"IMPOSSIBLE\n"; return 0;}
    //cnt[i] stores the max distance from node i to node n
    //flag[i] denotes if we can reach node n from node i or not
    cout<<cnt[1]+1<<"\n";
    cout<<"1 ";
    ll z=1;
    while(child[z]!=n){
        cout<<child[z]<<" ";
        z=child[z];
    }
    cout<<n;
    return 0;
}