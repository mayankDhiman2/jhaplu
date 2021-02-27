#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <int> A = {1, 2, 3, 4};
	int c1 = 2, c2 = 1, n = A.size(), lo = *min_element(A.begin(), A.end()), hi = *max_element(A.begin(), A.end());
	sort(A.begin(), A.end());
	vector <int> pref_sum(A.size() + 1);
	for (int i = 1; i < pref_sum.size(); i ++)
		pref_sum[i] = pref_sum[i - 1] + A[i - 1];
	int result = 2e9;
	for (int lev = lo; lev <= hi; lev ++){
		int ix = lower_bound(A.begin(), A.end(), lev) - A.begin();
		int lef_num = ix, lef_sum = pref_sum[ix], rt_num = n - ix, rt_sum = pref_sum[n] - pref_sum[ix];
		result = min(result, c1*(lef_num*lev - lef_sum) + c2*(rt_sum - rt_num*lev));
	}
	cout << result << "\n";
}