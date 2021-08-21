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
using vvb = vector<vector<bool>>;
using vpii = vector<pair<ll,ll>>;

ll n, m, cnt=0;
char matrix[1001][1001];
bool visited[1001][1001];
int prevStep[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
//0-U, 1-R, 2-D, 3-L
string steps = "URDL";
vector<char> ans;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m;
    pii begin, end;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]=='A') begin = mp(i, j);
            else if(matrix[i][j]=='B') end = mp(i, j);
            visited[i][j] = false;
        }
    }
    queue<pii> q;
    q.push(begin);
    while(!q.empty()){
        pii u = q.front();
        visited[u.f][u.s] = true;
        q.pop();
        for(int i=0;i<4;i++){
            ll x = u.f + dx[i];
            ll y = u.s + dy[i];
            if(x<=0||y<=0||x>n||y>m||matrix[x][y]=='#'||visited[x][y]) continue;
            visited[x][y] = true;
            prevStep[x][y] = i;
            q.push({x, y});
        }
    }

    if(visited[end.f][end.s]){
        cout<<"YES"<<endl;
        while(end!=begin){
            int i = prevStep[end.f][end.s];
            ans.pb(steps[i]);
            end.f = end.f - dx[i];
            end.s = end.s - dy[i];
        }
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for(auto c: ans) cout<<c;
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
