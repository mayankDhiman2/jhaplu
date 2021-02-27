#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int N;

	function<ll(ll, ll)> dp = [&](ll i, ll pre){
		if (i == N)
			return 1ll;
		ll res = 0, mod = 1e9 + 7;
		if (pre == 0){
			res += dp(i + 1, 1);
			res %= mod;
		}else{
			res += dp(i + 1, pre);
			res %= mod;
			res += dp(i + 1, pre + 1);
			res %= mod;
		}
		return res;
	};

	vector <int> prob = {1, 2, 7};
	for (int p : prob){
		N = p;
		cout << dp(0, 0) << '\n';
	}
}