// implementation of topological sort
#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using vbb = vector<vector<bool>>;
#define mp make_pair
#define pb push_back
vii adj_list;
vi visited;
vi top_sort;

void dfs(int node){
    for(int u: adj_list[node]){
        if(!visited[u]){
            visited[u]=true;
            dfs(u);
        }
    }
    top_sort.pb(node);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, m; cin>>n>>m;
    adj_list.resize(n+1);
    visited.resize(n+1);
    fill(visited.begin(), visited.end(), 0);
    while(m--){
        int x, y;cin>>x>>y;
        adj_list[x].pb(y);
    }
    for(int i=1;i<=n;i++)
        if(!visited[i]) { visited[i]=1; dfs(i);}
    reverse(top_sort.begin(), top_sort.end());
    vi index(n+1);
    for(int i=0;i<n;i++) index[top_sort[i]]=i;
    for(int i=1;i<=n;i++) for(int j: adj_list[i]) if(index[j]<=index[i]){cout<<"IMPOSSIBLE"<<endl; return 0;}
    for(int x : top_sort) cout<<x<<" ";
    cout<<endl;

    return 0;
}