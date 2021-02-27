#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector <int> A(N);
	for (int& a : A)
		cin >> a;
	vector<int> cache(N, -1);
	function<int(int, bool)> dp = [&](int i, bool can_skip){
		if (i == N)
			return 0;
		if (cache[i] != -1)
			return cache[i];
		int res = 2e9;
		if (can_skip)
			res = min(res, dp(i + 1, 0));
		res = min(res, A[i] + dp(i + 1, 1));
		return cache[i] = res;
	};
	cout << dp(0, 1) << '\n';
}