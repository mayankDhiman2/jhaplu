#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	vector <int> A = {9, 5, 2, 9, 4};
	int N = A.size();
	function<int(int, bool)> dp = [&](int i, bool alice){
		if (i == N)
			return 0;
		int res = -2e9;
		if (!alice)
			res = max(dp(i + 1, alice), A[i] + dp(i + 1, 1^alice));
		else
			res = max(dp(i + 1, alice), -A[i] + dp(i + 1, 1^alice));
		return res;
	};
	cout << dp(0, 0) << "\n";
}