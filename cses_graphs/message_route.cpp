#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back 

int main(){
    int n, m;
    cin>>n>>m;
    vi dist(n+1, INT_MAX);
    vi parent(n+1);
    vector<vi> adj_list(n+1);

    while(m--){
        int x, y;
        cin>>x>>y;
        adj_list[x].pb(y);
        adj_list[y].pb(x);
    }

    queue<int> q;
    dist[1]=0;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj_list[u]){
            if(dist[v]==INT_MAX){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if(dist[n]==INT_MAX) cout<<"IMPOSSIBLE"<<endl;
    else{
        cout<<dist[n]+1<<endl;
        vi v{n};
        while(v.back()!=1){
            v.pb(parent[v.back()]);
        }
        reverse(begin(v), end(v));
        for(int x: v)
            cout<<x<<" ";
    }
    return 0;

}