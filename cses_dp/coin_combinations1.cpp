#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long 
using vi = vector<int>;

ll dp[1000001];
const int MOD = (int) 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
	int n, x; 
    cin>>n>>x;
	vi coins(n);
	for(int i=0;i<n;i++)
		cin>>coins[i];
	dp[0]=1;
	for (int i=1;i<=x;i++){
		for (int c:coins){
			if(i-c>= 0){
				dp[i] += dp[i-c];
				dp[i] %= MOD;
			}
		}
	}
	cout<<dp[x]<<endl;
}