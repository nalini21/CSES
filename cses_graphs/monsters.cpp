#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int paths[1001][1001];
pii from[1001][1001];
int MAXD = INT_MAX;
pii A;
int n, m;
queue<pii> q;
string ans;
bool possible = false;

void retrace(pii node){  
	pii origin = from[node.first][node.second];
	if(origin ==  pii(0,0)) return;
	if(origin.first == node.first+1) ans.push_back('U');
	if(origin.first == node.first-1) ans.push_back('D');
	if(origin.second == node.second+1) ans.push_back('L');
	if(origin.second==node.second-1) ans.push_back('R');
	retrace(origin);
}
void check(pii origin, pii dest){ // check if the considered destination may be traveled to
	int pl = paths[origin.first][origin.second];
	if(pl+1<paths[dest.first][dest.second]){
		paths[dest.first][dest.second]  = pl+1;
		q.push(dest);
		from[dest.first][dest.second] = origin;
	}
}
bool mora = false; // false if bfs for monsters, true if bfs for A
void bfs(){
	while(!q.empty()){
		pii loc = q.front(), next; q.pop();
		next = loc; next.first++; check(loc, next); 
		next = loc; next.first--; check(loc, next);
		next = loc; next.second++; check(loc, next);
		next = loc; next.second--; check(loc, next);
		if(mora && (loc.first == 1 || loc.second == 1 || loc.first == n || loc.second == m)){
			cout << "YES" << endl;
			cout << paths[loc.first][loc.second] << endl;
			retrace(loc);
			possible = true;
			return;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;
		cin >> s;
		for(int j=1;j<=m; j++){
			paths[i][j] = MAXD;
			if(s[j-1] == '#') paths[i][j] = 0;
			if(s[j-1] == 'M') {q.push(pii(i,j)); paths[i][j]  = 0;}
			if(s[j-1] == 'A') {A.first = i; A.second = j;}
		}
	}
	bfs(); 
	mora = true; 
	from[A.first][A.second] = pii(0,0); 
	paths[A.first][A.second] = 0; q.push(A); 
	bfs(); 
	if(possible){
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	else cout << "NO" << endl;
}