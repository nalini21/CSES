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
	int x; 
    cin>>x;
	vi diceValues = {1,2,3,4,5,6};
	dp[0]=1;
	for (int i=1;i<=x;i++){
		for (int d:diceValues){
			if(i-d>= 0){
				dp[i] += dp[i-d];
				dp[i] %= MOD;
			}
		}
	}
	cout<<dp[x]<<endl;
}